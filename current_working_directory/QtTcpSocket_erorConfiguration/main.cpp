#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>

class TcpClient : public QObject {
    Q_OBJECT
public:
    TcpClient(QObject *parent = nullptr) : QObject(parent) {
        socket = new QTcpSocket(this);
        connect(socket, &QTcpSocket::connected, this, &TcpClient::onConnected);
        connect(socket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
        connect(socket, &QTcpSocket::disconnected, this, &TcpClient::onDisconnected);
    }

    void connectToHost(const QString &host, quint16 port) {
        socket->connectToHost(host, port);
    }

private slots:
    void onConnected() {
        qDebug() << "Connected to server";
        socket->write("Hello, Server!");
    }

    void onReadyRead() {
        qDebug() << "Reading from server:" << socket->readAll();
    }

    void onDisconnected() {
        qDebug() << "Disconnected from server";
    }

private:
    QTcpSocket *socket;
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    TcpClient client;
    client.connectToHost("example.com", 1234);
    return a.exec();
}
