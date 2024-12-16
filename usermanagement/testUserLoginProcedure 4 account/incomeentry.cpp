#include "incomeentry.h"
#include "ui_incomeentry.h"
#include <QSqlQuery>
#include <QMessageBox>

IncomeEntry::IncomeEntry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IncomeEntry)
{
    ui->setupUi(this);
    connect(ui->saveIncomeButton, &QPushButton::clicked, this, &IncomeEntry::onSaveIncomeButtonClicked);
}

IncomeEntry::~IncomeEntry()
{
    delete ui;
}

void IncomeEntry::onSaveIncomeButtonClicked()
{
    QString source = ui->sourceLineEdit->text();
    double amount = ui->amountLineEdit->text().toDouble();
    QDate date = ui->dateEdit->date();

    if (source.isEmpty() || amount <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid source and amount.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO IncomeEntry (userID, source, amount, date) VALUES (?, ?, ?, ?)");
    query.addBindValue(1); // Replace with the actual userID
    query.addBindValue(source);
    query.addBindValue(amount);
    query.addBindValue(date);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Income entry saved successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to save income entry.");
    }
}
