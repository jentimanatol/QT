#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void startListening();
    void requestConnection();
    void acceptConnection();
    void clientSendMessageToServer();
    void updateServerProgress();
    void updateClientProgress(qint64 numBytes);
    void displayError(QAbstractSocket::SocketError socketError);

private:
    Ui::Dialog *ui;
    QTcpServer tcpServer;
    QTcpSocket tcpClient;
    QTcpSocket *tcpServerConnection;
    int bytesToWrite;
    int bytesWritten;
    int bytesReceived;
};

#endif // DIALOG_H
