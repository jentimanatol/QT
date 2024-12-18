#include "Expense.h"

Expense::Expense(QDate date, QString category, QString subcategory, double amount)
    : date(date), category(category), subcategory(subcategory), amount(amount) {}

QDate Expense::getDate() const {
    return date;
}

QString Expense::getCategory() const {
    return category;
}

QString Expense::getSubcategory() const {
    return subcategory;
}

double Expense::getAmount() const {
    return amount;
}

void Expense::setDate(QDate date) {
    this->date = date;
}

void Expense::setCategory(QString category) {
    this->category = category;
}

void Expense::setSubcategory(QString subcategory) {
    this->subcategory = subcategory;
}

void Expense::setAmount(double amount) {
    this->amount = amount;
}
