#include "welcome.h"
#include "ui_welcome.h"
#include "incomeentry.h"
#include "expenseentry.h"
#include "totalbalance.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);

    // Connect buttons to their slots
    connect(ui->incomeEntryButton, &QPushButton::clicked, this, &Welcome::onIncomeEntryButtonClicked);
    connect(ui->expenseEntryButton, &QPushButton::clicked, this, &Welcome::onExpenseEntryButtonClicked);
    connect(ui->totalBalanceButton, &QPushButton::clicked, this, &Welcome::onTotalBalanceButtonClicked);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::onIncomeEntryButtonClicked()
{
    IncomeEntry *incomeEntryWindow = new IncomeEntry();
    incomeEntryWindow->show();
}

void Welcome::onExpenseEntryButtonClicked()
{
    ExpenseEntry *expenseEntryWindow = new ExpenseEntry();
    expenseEntryWindow->show();
}

void Welcome::onTotalBalanceButtonClicked()
{
    TotalBalance *totalBalanceWindow = new TotalBalance();
    totalBalanceWindow->show();
}
