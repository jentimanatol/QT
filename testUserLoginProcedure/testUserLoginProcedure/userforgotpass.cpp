#include "userforgotpass.h"
#include "ui_userforgotpass.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>

UserForgotPass::UserForgotPass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserForgotPass)
{
    ui->setupUi(this);

    // Connect the forgot password button to the forgot password procedure execution
    connect(ui->forgotPasswordButton, &QPushButton::clicked, this, &UserForgotPass::onForgotPasswordButtonClicked);
}

UserForgotPass::~UserForgotPass()
{
    delete ui;
}

// Function to execute the forgot password procedure
void UserForgotPass::executeForgotPasswordProcedure(const QString &username, const QString &newPassword) {
    QSqlQuery query;

    query.prepare("CALL ForgotPassword(:username, :newPassword)");
    query.bindValue(":username", username);
    query.bindValue(":newPassword", newPassword);

    if (!query.exec()) {
        qDebug() << "Procedure execution failed:" << query.lastError().text();
        QMessageBox::critical(this, "Procedure Execution Failed", query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Password Reset", "Password reset successfully!");
}

// Slot for forgot password button click
void UserForgotPass::onForgotPasswordButtonClicked() {
    QString username = QInputDialog::getText(this, "Forgot Password", "Enter your username:");
    QString newPassword = QInputDialog::getText(this, "Forgot Password", "Enter your new password:", QLineEdit::Password);

    executeForgotPasswordProcedure(username, newPassword);
}
