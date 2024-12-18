#include "ExpenseEntry.h"
#include "ui_ExpenseEntry.h"
#include "MenuWindow.h" // Include the MenuWindow header

ExpenseEntry::ExpenseEntry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExpenseEntry),
    menuWindow(nullptr)
{
    ui->setupUi(this);

    // Connect the Return to Menu button to the slot
    connect(ui->returnToMenuButton, &QPushButton::clicked, this, &ExpenseEntry::onReturnToMenuButtonClicked);
}

ExpenseEntry::~ExpenseEntry()
{
    delete ui;
    if (menuWindow) {
        delete menuWindow;
    }
}

void ExpenseEntry::onReturnToMenuButtonClicked()
{
    if (!menuWindow) {
        menuWindow = new MenuWindow();
    }
    menuWindow->show();
    this->hide(); // Hide the ExpenseEntry window
}
