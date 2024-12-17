#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginButtonClicked();

private:
    void connectToDatabase();
    void executeLoginProcedure(const QString &email, const QString &password);

    Ui::MainWindow *ui;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
