#include "mytcpclient.h"

MyTcpClient::MyTcpClient(QObject *parent) : QObject(parent) {
    connect(&socket, &QTcpSocket::connected, this, &MyTcpClient::connected);
    connect(&socket, &QTcpSocket::disconnected, this, &MyTcpClient::disconnected);
    connect(&socket, &QTcpSocket::readyRead, this, &MyTcpClient::readyRead);
}

void MyTcpClient::doConnect(const QString &host) {
    socket.connectToHost(host, 80);
}

void MyTcpClient::connected() {
    qDebug() << "Connected!";
    socket.write("GET / HTTP/1.1\r\nHost: " + socket.peerName().toUtf8() + "\r\n\r\n");
}

void MyTcpClient::disconnected() {
    qDebug() << "Disconnected!";
}

void MyTcpClient::readyRead() {
    qDebug() << "Reading:" << socket.bytesAvailable();
    qDebug() << socket.readAll();
}
