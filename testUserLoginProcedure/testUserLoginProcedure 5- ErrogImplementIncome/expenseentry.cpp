#include "expenseentry.h"
#include "ui_expenseentry.h"

ExpenseEntry::ExpenseEntry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExpenseEntry)
{
    ui->setupUi(this);
}

ExpenseEntry::~ExpenseEntry()
{
    delete ui;
}
