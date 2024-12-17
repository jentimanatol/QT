#include "MenuWindow.h"
#include "ui_MenuWindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWindow),
    incomeEntryWindow(nullptr),
    expenseEntryWindow(nullptr),
    totalBalanceWindow(nullptr),
    logWindow(nullptr)
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->incomeButton, &QPushButton::clicked, this, &MenuWindow::onIncomeButtonClicked);
    connect(ui->expenseButton, &QPushButton::clicked, this, &MenuWindow::onExpenseButtonClicked);
    connect(ui->totalButton, &QPushButton::clicked, this, &MenuWindow::onTotalButtonClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &MenuWindow::onLogoutButtonClicked);
}

MenuWindow::~MenuWindow()
{
    delete ui;
    if (incomeEntryWindow) {
        delete incomeEntryWindow;
    }
    if (expenseEntryWindow) {
        delete expenseEntryWindow;
    }
    if (totalBalanceWindow) {
        delete totalBalanceWindow;
    }
    if (logWindow) {
        delete logWindow;
    }
}

void MenuWindow::onIncomeButtonClicked()
{
    if (!incomeEntryWindow) {
        incomeEntryWindow = new IncomeEntry();
    }
    incomeEntryWindow->show();
    this->hide(); // Hide the MenuWindow
}

void MenuWindow::onExpenseButtonClicked()
{
    if (!expenseEntryWindow) {
        expenseEntryWindow = new ExpenseEntry();
    }
    expenseEntryWindow->show();
    this->hide(); // Hide the MenuWindow
}

void MenuWindow::onTotalButtonClicked()
{
    if (!totalBalanceWindow) {
        totalBalanceWindow = new TotalBalance();
    }
    totalBalanceWindow->show();
    this->hide(); // Hide the MenuWindow
}

void MenuWindow::onLogoutButtonClicked()
{
    if (!logWindow) {
        logWindow = new LogWindow();
    }
    logWindow->show();
    this->hide(); // Hide the MenuWindow
}
