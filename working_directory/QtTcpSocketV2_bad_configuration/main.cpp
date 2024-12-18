#include <QCoreApplication>
#include <QSslSocket>
#include <QDebug>


class SslClient : public QObject {
    Q_OBJECT
public:
    SslClient(QObject *parent = nullptr) : QObject(parent) {
        socket = new QSslSocket(this);
        connect(socket, &QSslSocket::encrypted, this, &SslClient::onConnected);
        connect(socket, &QSslSocket::readyRead, this, &SslClient::onReadyRead);
        connect(socket, &QSslSocket::disconnected, this, &SslClient::onDisconnected);
        connect(socket, QOverload<const QList<QSslError>&>::of(&QSslSocket::sslErrors),
                this, &SslClient::onSslErrors);
    }

    void connectToHost(const QString &host, quint16 port) {
        socket->connectToHostEncrypted(host, port);
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

    void onSslErrors(const QList<QSslError> &errors) {
        for (const QSslError &error : errors) {
            qDebug() << "SSL Error:" << error.errorString();
        }
        socket->ignoreSslErrors();
    }

private:
    QSslSocket *socket;
};


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    SslClient client;
    client.connectToHost("www.google.com", 443);
    return a.exec();
}

