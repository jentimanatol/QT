#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include <QMessageBox>
#include <QDebug>

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    connect(ui->incomeButton, &QPushButton::clicked, this, &WelcomeWindow::onIncomeButtonClicked);
    connect(ui->expenseButton, &QPushButton::clicked, this, &WelcomeWindow::onExpenseButtonClicked);
    connect(ui->totalButton, &QPushButton::clicked, this, &WelcomeWindow::onTotalButtonClicked);
}

WelcomeWindow::~WelcomeWindow()
{
    //delete ui;
}

void WelcomeWindow::setUserDetails(const QString &firstName, const QString &lastName, int userID)
{
    ui->userFirstNameLabel->setText("First Name: " + firstName);
    ui->userLastNameLabel->setText("Last Name: " + lastName);
    ui->userIDLabel->setText("User ID: " + QString::number(userID));
}

void WelcomeWindow::onIncomeButtonClicked()
{
    qDebug() << "Button pressed";
    // IncomeEntry *incomePage = new IncomeEntry(this);
    // incomePage->show();
}

void WelcomeWindow::onExpenseButtonClicked()
{
    qDebug() << "Button pressed";
    // ExpenseEntry *expensePage = new ExpenseEntry(this);
    // expensePage->show();
}

void WelcomeWindow::onTotalButtonClicked()
{
    qDebug() << "Button pressed";
    // TotalBalance *totalPage = new TotalBalance(this);
    // totalPage->show();
}
