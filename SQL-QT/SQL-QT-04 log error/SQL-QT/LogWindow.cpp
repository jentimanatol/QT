#include "LogWindow.h"
#include "ui_LogWindow.h"
#include <QMessageBox>

LogWindow::LogWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWindow)  // Initialize the UI
{
    ui->setupUi(this);

    // Connect login button to the slot
    connect(ui->pushButtonLogin, &QPushButton::clicked, this, &LogWindow::onLoginClicked);
}

LogWindow::~LogWindow() {
    delete ui;  // Clean up UI
}

void LogWindow::onLoginClicked() {
    QString email = ui->lineEditEmail->text();
    QString password = ui->lineEditPassword->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Please enter both email and password.");
        return;
    }

    // Validate the user using the DatabaseManager
    if (DatabaseManager::instance().validateUser(email, password)) {
        QMessageBox::information(this, "Login Successful", "Welcome!");
        // Proceed to the next window (if necessary)
    } else {
        QMessageBox::critical(this, "Login Failed", "Invalid email or password.");
    }
}
