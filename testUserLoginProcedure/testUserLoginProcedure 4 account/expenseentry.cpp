#include "expenseentry.h"
#include "ui_expenseentry.h"
#include <QSqlQuery>
#include <QMessageBox>

ExpenseEntry::ExpenseEntry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExpenseEntry)
{
    ui->setupUi(this);
    connect(ui->saveExpenseButton, &QPushButton::clicked, this, &ExpenseEntry::onSaveExpenseButtonClicked);
}

ExpenseEntry::~ExpenseEntry()
{
    delete ui;
}

void ExpenseEntry::onSaveExpenseButtonClicked()
{
    QString category = ui->categoryLineEdit->text();
    QString subcategory = ui->subcategoryLineEdit->text();
    double amount = ui->amountLineEdit->text().toDouble();
    QDate date = ui->dateEdit->date();

    if (category.isEmpty() || subcategory.isEmpty() || amount <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid category, subcategory, and amount.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO ExpenseEntry (userID, category, subcategory, amount, date) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(1); // Replace with the actual userID
    query.addBindValue(category);
    query.addBindValue(subcategory);
    query.addBindValue(amount);
    query.addBindValue(date);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Expense entry saved successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to save expense entry.");
    }
}
