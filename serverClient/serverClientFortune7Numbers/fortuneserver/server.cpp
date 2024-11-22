// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QtWidgets>
#include <QtNetwork>
#include <QtCore>
#include <QRandomGenerator>

#include "server.h"

Server::Server(QWidget *parent)
    : QDialog(parent)
    , statusLabel(new QLabel)
{
    statusLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);

    initServer();

    //! [2]
    // Initialize fortunes with a placeholder
    fortunes << tr("Lucky numbers will be generated on request.");
    //! [2]
    auto quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);
    connect(quitButton, &QAbstractButton::clicked, this, &QWidget::close);
    //! [3]
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::sendFortune);
    //! [3]

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = nullptr;
    if (QGuiApplication::styleHints()->showIsFullScreen() || QGuiApplication::styleHints()->showIsMaximized()) {
        auto outerVerticalLayout = new QVBoxLayout(this);
        outerVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));
        auto outerHorizontalLayout = new QHBoxLayout;
        outerHorizontalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored));
        auto groupBox = new QGroupBox(QGuiApplication::applicationDisplayName());
        mainLayout = new QVBoxLayout(groupBox);
        outerHorizontalLayout->addWidget(groupBox);
        outerHorizontalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored));
        outerVerticalLayout->addLayout(outerHorizontalLayout);
        outerVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));
    } else {
        mainLayout = new QVBoxLayout(this);
    }

    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(buttonLayout);

    setWindowTitle(QGuiApplication::applicationDisplayName());
}

void Server::initServer()
{
    //! [0] //! [1]
    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen()) {
        QMessageBox::critical(this, tr("Fortune Server"),
                              tr("Unable to start the server: %1.")
                                  .arg(tcpServer->errorString()));
        close();
        return;
    }
    //! [0]
    QString ipAddress;
    const QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (const QHostAddress &entry : ipAddressesList) {
        if (entry != QHostAddress::LocalHost && entry.toIPv4Address()) {
            ipAddress = entry.toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Fortune Client example now.")
                             .arg(ipAddress).arg(tcpServer->serverPort()));
    //! [1]
}

//! [4]
void Server::sendFortune()
{
    //! [5]
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    // Generate 7 random numbers and store them in a single string
    QString luckyNumbers;
    for (int i = 0; i < 7; ++i) {
        luckyNumbers.append(QString::number(QRandomGenerator::global()->bounded(1, 100)));
        if (i < 6) {
            luckyNumbers.append(" ");
        }
    }
    QString fortune = tr("Lucky numbers: %1").arg(luckyNumbers);

    out << fortune;
    //! [4] //! [7]

    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QAbstractSocket::disconnected,
            clientConnection, &QObject::deleteLater);
    //! [7] //! [8]

    clientConnection->write(block);
    clientConnection->disconnectFromHost();
    //! [5]
}
//! [8]
