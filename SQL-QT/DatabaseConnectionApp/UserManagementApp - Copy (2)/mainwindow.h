\#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>    // Include for QMainWindow
#include <QSqlDatabase>   // Include for QSqlDatabase
#include <QPushButton>    // Include for QPushButton
#include <QLineEdit>      // Include for QLineEdit
#include <QStackedWidget> // Include for QStackedWidget
#include <QComboBox>      // Include for QComboBox
#include <QWidget>        // Include for QWidget

    namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showRegisterForm();
    void showLoginForm();
    void loginUser();
    void registerUser();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QWidget *registerPage;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *registerUsernameLineEdit;
    QLineEdit *registerPasswordLineEdit;
    QComboBox *positionComboBox;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QPushButton *forgotPasswordButton;
    QPushButton *registerUserButton;
    QPushButton *backToLoginButton;
};

#endif // MAINWINDOW_H
