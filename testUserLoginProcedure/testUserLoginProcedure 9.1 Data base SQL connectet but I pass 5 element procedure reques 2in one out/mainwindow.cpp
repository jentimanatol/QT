#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "welcomewindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectToDatabase();
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("usermanagement");
    db.setUserName("root");
    db.setPassword("admin");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Connection Failed", db.lastError().text());
    } else {
        QMessageBox::information(this, "Database Connection", "Database connected successfully!");
    }
}

void MainWindow::executeLoginProcedure(const QString &email, const QString &password)
{
    QSqlQuery query;
    query.prepare("CALL UserLoginProcedure(:email, :password, @userID, @firstName, @lastName)");
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Procedure Execution Failed", query.lastError().text());
        return;
    }

    if (!query.exec("SELECT @userID, @firstName, @lastName")) {
        QMessageBox::critical(this, "Output Retrieval Failed", query.lastError().text());
        return;
    }

    if (query.next()) {
        int userID = query.value(0).toInt();
        QString firstName = query.value(1).toString();
        QString lastName = query.value(2).toString();

        WelcomeWindow *welcomeWindow = new WelcomeWindow();
        welcomeWindow->setUserDetails(firstName, lastName, userID);
        welcomeWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid email or password.");
    }
}

void MainWindow::onLoginButtonClicked()
{
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    executeLoginProcedure(email, password);
}
