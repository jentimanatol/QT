#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "DatabaseManager.h"
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

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Please enter both email and password.");
    } else {
        int userID;
        bool loginSuccessful = DatabaseManager::instance().executeLoginProcedure(email, password, userID);

        if (loginSuccessful && userID > 0) {
            QMessageBox::information(this, "Login Successful", "Welcome!");
            // Proceed to the next step, e.g., open the main window
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid email or password.");
        }
    }
}
