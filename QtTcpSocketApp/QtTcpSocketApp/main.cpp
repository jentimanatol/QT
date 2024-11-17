#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>

void doConnect() {
    QTcpSocket socket;
    socket.connectToHost("www.bhcc.edu", 80);

    if (socket.waitForConnected(3000)) {
        qDebug() << "Connected!";
        socket.write("GET / HTTP/1.1\r\nHost: bhcc.edu\r\n\r\n");
        socket.waitForBytesWritten(1000);
        socket.waitForReadyRead(3000);
        qDebug() << "Reading:" << socket.bytesAvailable();
        qDebug() << socket.readAll();
        socket.close();
    } else {
        qDebug() << "Not connected!";
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    doConnect();
    return a.exec();
}
