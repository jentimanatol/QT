#ifndef MYTCPCLIENT_H
#define MYTCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class MyTcpClient : public QObject {
    Q_OBJECT

public:
    MyTcpClient(QObject *parent = nullptr);
    void doConnect(const QString &host);

private slots:
    void connected();
    void disconnected();
    void readyRead();

private:
    QTcpSocket socket;
};

#endif // MYTCPCLIENT_H
