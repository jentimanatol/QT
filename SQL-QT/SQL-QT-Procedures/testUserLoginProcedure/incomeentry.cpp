#include "incomeentry.h"
#include "ui_incomeentry.h"

IncomeEntry::IncomeEntry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IncomeEntry)
{
    ui->setupUi(this);
}

IncomeEntry::~IncomeEntry()
{
    delete ui;
}
