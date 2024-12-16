#include "userregister.h"
#include "ui_userregister.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

UserRegister::UserRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserRegister)
{
    ui->setupUi(this);

    // Connect the register button to the register procedure execution
    connect(ui->registerUserButton, &QPushButton::clicked, this, &UserRegister::onRegisterButtonClicked);
}

UserRegister::~UserRegister()
{
    delete ui;
}

// Function to execute the registration procedure
void UserRegister::executeRegisterProcedure(const QString &firstName, const QString &lastName, const QString &username, const QString &password, const QString &position) {
    QSqlQuery query;

    query.prepare("CALL RegisterUser(:firstName, :lastName, :username, :password, :position, @userID)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":position", position);

    if (!query.exec()) {
        qDebug() << "Procedure execution failed:" << query.lastError().text();
        QMessageBox::critical(this, "Procedure Execution Failed", query.lastError().text());
        return;
    }

    if (!query.exec("SELECT @userID")) {
        qDebug() << "Failed to retrieve output variable:" << query.lastError().text();
        QMessageBox::critical(this, "Output Retrieval Failed", query.lastError().text());
        return;
    }

    if (query.next()) {
        int userID = query.value(0).toInt();
        qDebug() << "New user ID:" << userID;

        QMessageBox::information(this, "Registration Successful", "User registered successfully!");
    } else {
        QMessageBox::warning(this, "Registration Failed", "Failed to register the user.");
    }
}

// Slot for register button click
void UserRegister::onRegisterButtonClicked() {
    QString firstName = ui->firstNameLineEdit->text();
    QString lastName = ui->lastNameLineEdit->text();
    QString username = ui->registerUsernameLineEdit->text();
    QString password = ui->registerPasswordLineEdit->text();
    QString position = ui->positionComboBox->currentText();

    executeRegisterProcedure(firstName, lastName, username, password, position);
}
