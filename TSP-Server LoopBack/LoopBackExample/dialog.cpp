#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , tcpServer(new QTcpServer(this))
    , tcpSocket(new QTcpSocket(this))
    , clientSocket(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Loopback Example - Your Name");

    connect(ui->startServerButton, &QPushButton::clicked, this, &Dialog::startServer);
    connect(ui->connectButton, &QPushButton::clicked, this, &Dialog::connectToServer);
    connect(tcpServer, &QTcpServer::newConnection, this, &Dialog::acceptConnection);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::startServer()
{
    if (!tcpServer->listen(QHostAddress::LocalHost, 1234)) {
        ui->logTextEdit->append("Server could not start!");
    } else {
        ui->logTextEdit->append("Server started...");
    }
}

void Dialog::connectToServer()
{
    tcpSocket->connectToHost(QHostAddress::LocalHost, 1234);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Dialog::startRead);
    ui->logTextEdit->append("Connecting to server...");
}

void Dialog::acceptConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &Dialog::startRead);
    ui->logTextEdit->append("Client connected...");
}

void Dialog::startRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket) {
        QByteArray data = socket->readAll();
        ui->logTextEdit->append("Received: " + data);
        socket->write(data);
    }
}
