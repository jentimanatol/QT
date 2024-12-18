#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class LogWindow;
}

class LogWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent = nullptr);
    ~LogWindow();

private slots:
    void onLoginClicked();
    void onRegisterClicked();

private:
    Ui::LogWindow *ui;

    QPushButton *pushButtonLogin;
    QPushButton *pushButtonRegister;
    QLabel *labelEmail;
    QLabel *labelPassword;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditPassword;

    QSqlDatabase db;  // Database connection
    bool openDatabase();
    bool registerUser(const QString &email, const QString &password);
};

#endif // LOGWINDOW_H
