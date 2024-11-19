#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void startServer();
    void connectToServer();
    void acceptConnection();
    void startRead();

private:
    Ui::Dialog *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QTcpSocket *clientSocket;
};

#endif // DIALOG_H
