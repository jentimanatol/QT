#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DatabaseManager.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , userID(-1)  // Initialize userID to an invalid value
{
    ui->setupUi(this);
    if (DatabaseManager::instance().connectToDatabase()) {
        QMessageBox::information(this, "Database Connection", "Database connected successfully!");
    } else {
        QMessageBox::critical(this, "Database Connection Failed", "Failed to connect to the database.");
    }

    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::executeLoginProcedure(const QString &email, const QString &password) {
    if (DatabaseManager::instance().executeLoginProcedure(email, password, userID)) {
        if (userID == 0) {
            QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
            ui->emailLineEdit->clear();
            ui->passwordLineEdit->clear();
            ui->emailLineEdit->setFocus();
        } else {
            qDebug() << "UserID:" << userID;
            QMessageBox::information(this, "Login Result", "User ID: " + QString::number(userID));
            // Proceed to the next UI step, e.g., show WelcomeWindow
        }
    } else {
        QMessageBox::critical(this, "Procedure Execution Failed", "Failed to execute login procedure.");
    }
}



void MainWindow::onLoginButtonClicked() {
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    executeLoginProcedure(email, password);
}
