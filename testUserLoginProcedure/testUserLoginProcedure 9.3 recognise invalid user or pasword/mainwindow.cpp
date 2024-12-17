#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , userID(-1)  // Initialize userID to an invalid value
{
    ui->setupUi(this);
    connectToDatabase();

    // Connect the login button to the login procedure execution
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("usermanagement");
    db.setUserName("root");
    db.setPassword("admin");
    db.setPort(3306);

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        QMessageBox::critical(this, "Database Connection Failed", db.lastError().text());
    } else {
        qDebug() << "Database connected successfully!";
        QMessageBox::information(this, "Database Connection", "Database connected successfully!");
    }
}

void MainWindow::executeLoginProcedure(const QString &email, const QString &password) {
    QSqlQuery query;
    qDebug() << "Preparing query...";

    query.prepare("CALL UserLoginProcedure(:email, :password, @userID)");
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    qDebug() << "Executing query...";
    if (!query.exec()) {
        qDebug() << "Procedure execution failed:" << query.lastError().text();
        QMessageBox::critical(this, "Procedure Execution Failed", query.lastError().text());
        return;
    }

    qDebug() << "Retrieving output...";
    if (!query.exec("SELECT @userID")) {
        qDebug() << "Failed to retrieve output variables:" << query.lastError().text();
        QMessageBox::critical(this, "Output Retrieval Failed", query.lastError().text());
        return;
    }

    if (query.next()) {
        userID = query.value(0).toInt();  // Save the userID
        if (userID == 0) {
            qDebug() << "Invalid username or password.";
            QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
        } else {
            qDebug() << "UserID:" << userID;
            QMessageBox::information(this, "Login Result", "User ID: " + QString::number(userID));
            // Proceed to the next UI step, e.g., show WelcomeWindow
        }
    } else {
        qDebug() << "No user found.";
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void MainWindow::onLoginButtonClicked() {
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    qDebug() << "Email:" << email << "Password:" << password;
    executeLoginProcedure(email, password);
}
