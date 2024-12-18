#include "LogWindow.h"
#include "ui_LogWindow.h" // Include the generated UI header

LogWindow::LogWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWindow),
    userID(-1)
{
    ui->setupUi(this); // Sets up the UI elements from the .ui file

    if (!DatabaseManager::instance().connectToDatabase()) {
        QMessageBox::critical(this, "Error", "Failed to connect to the database.");
        return;
    }

    connect(ui->loginButton, &QPushButton::clicked, this, &LogWindow::attemptLogin);
}

LogWindow::~LogWindow()
{
    delete ui; // Properly deletes the UI object
}

void LogWindow::attemptLogin()
{
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (DatabaseManager::instance().loginUser(email, password, userID)) {
        QMessageBox::information(this, "Login Successful", "Welcome, User ID: " + QString::number(userID));
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid email or password.");
    }
}
