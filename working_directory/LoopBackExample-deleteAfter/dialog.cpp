#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QDebug>

static const int TotalBytes = 50 * 1024 * 1024; // Total bytes to be transferred
static const int PayloadSize = 64 * 1024; // Size of each payload (64 KB)

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    tcpServer(new QTcpServer(this)),
    tcpSocket(new QTcpSocket(this)),
    clientSocket(nullptr),
    bytesToWrite(0),
    bytesWritten(0),
    bytesReceived(0)
{
    ui->setupUi(this);
    setWindowTitle("Loopback Example - Your Name");

    // Initially disable the request button
    ui->connectButton->setEnabled(false);

    // Connect signals and slots
    connect(ui->startServerButton, &QPushButton::clicked, this, &Dialog::startServer);
    connect(ui->connectButton, &QPushButton::clicked, this, &Dialog::connectToServer);
    connect(tcpServer, &QTcpServer::newConnection, this, &Dialog::acceptConnection);
    connect(tcpSocket, &QTcpSocket::connected, this, &Dialog::clientSendMessageToServer);
    connect(tcpSocket, &QTcpSocket::bytesWritten, this, &Dialog::updateClientProgress);
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error), this, &Dialog::displayError);
}

Dialog::~Dialog()
{
    delete ui;
}

// Start the server and listen for connections
void Dialog::startServer()
{
    ui->startServerButton->setEnabled(false);
    bytesWritten = 0;
    bytesReceived = 0;

    // Try to start the server
    while (!tcpServer->isListening() && !tcpServer->listen()) {
        QMessageBox::StandardButton ret = QMessageBox::critical(this,
                                                                tr("Loopback"),
                                                                tr("Unable to start the test: %1.")
                                                                    .arg(tcpServer->errorString()),
                                                                QMessageBox::Retry | QMessageBox::Cancel);
        if (ret == QMessageBox::Cancel)
            return;
    }

    ui->logTextEdit->append("Server started...");
    ui->connectButton->setEnabled(true);
}

// Connect to the server
void Dialog::connectToServer()
{
    ui->connectButton->setEnabled(false);
    ui->logTextEdit->append("Connecting to server...");
    tcpSocket->connectToHost(QHostAddress::LocalHost, tcpServer->serverPort());
}

// Accept a connection from the client
void Dialog::acceptConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &Dialog::updateServerProgress);
    connect(clientSocket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error), this, &Dialog::displayError);

    ui->logTextEdit->append("Client connected...");
    tcpServer->close();
}

// Send a message from the client to the server
void Dialog::clientSendMessageToServer()
{
    bytesToWrite = TotalBytes - (int)tcpSocket->write(QByteArray(PayloadSize, '@'));
    ui->logTextEdit->append("Client connected and sending data...");
}

// Update the server's progress bar
void Dialog::updateServerProgress()
{
    bytesReceived += (int)clientSocket->bytesAvailable();
    clientSocket->readAll();

    ui->serverProgressBar->setMaximum(TotalBytes);
    ui->serverProgressBar->setValue(bytesReceived);
    ui->logTextEdit->append(tr("Received %1MB").arg(bytesReceived / (1024 * 1024)));

    if (bytesReceived == TotalBytes) {
        clientSocket->close();
        ui->startServerButton->setEnabled(true);
#ifndef QT_NO_CURSOR
        QApplication::restoreOverrideCursor();
#endif
    }
}

// Update the client's progress bar
void Dialog::updateClientProgress(qint64 numBytes)
{
    bytesWritten += (int)numBytes;

    if (bytesToWrite > 0 && tcpSocket->bytesToWrite() <= 4 * PayloadSize)
        bytesToWrite -= (int)tcpSocket->write(QByteArray(qMin(bytesToWrite, PayloadSize), '@'));

    ui->clientProgressBar->setMaximum(TotalBytes);
    ui->clientProgressBar->setValue(bytesWritten);
    ui->logTextEdit->append(tr("Sent %1MB").arg(bytesWritten / (1024 * 1024)));
}

// Display any errors that occur
void Dialog::displayError(QAbstractSocket::SocketError socketError)
{
    if (socketError == QTcpSocket::RemoteHostClosedError)
        return;

    QMessageBox::information(this, tr("Network error"),
                             tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));

    tcpSocket->close();
    tcpServer->close();

    ui->clientProgressBar->reset();
    ui->serverProgressBar->reset();
    ui->logTextEdit->append("Client ready");
    ui->logTextEdit->append("Server ready");
    ui->startServerButton->setEnabled(true);
    ui->connectButton->setEnabled(false);
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
}
