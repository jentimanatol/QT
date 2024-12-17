#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include <QMessageBox>
#include <QDebug>

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &WelcomeWindow::onLoginButtonClicked);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::onLoginButtonClicked()
{
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    qDebug() << "Email:" << email << "Password:" << password;

    // Implement the login logic here
    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Please enter both email and password.");
    } else {
        // Replace with your actual login procedure
        bool loginSuccessful = (email == "test@example.com" && password == "password");

        if (loginSuccessful) {
            QMessageBox::information(this, "Login Successful", "Welcome!");
            // Proceed to the next step
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid email or password.");
        }
    }
}
