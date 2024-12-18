#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginButtonClicked();
    void onRegisterButtonClicked();
    void onForgotPasswordButtonClicked();


///Add for Buyget 
   
    void onIncomeEntryButtonClicked();
    void onExpenseEntryButtonClicked();

    void onTotalBalanceButtonClicked();


private:
    Ui::MainWindow *ui;
    void connectToDatabase();
    void executeLoginProcedure(const QString &username, const QString &password);
    void executeRegisterProcedure(const QString &firstName, const QString &lastName, const QString &username, const QString &password, const QString &position);
    void executeForgotPasswordProcedure(const QString &username, const QString &newPassword);
};

#endif // MAINWINDOW_H
