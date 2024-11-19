#include <QCoreApplication>

#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>


    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.


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


