#include "IncomeEntry.h"
#include "ui_IncomeEntry.h"
#include "MenuWindow.h" // Include the MenuWindow header

IncomeEntry::IncomeEntry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IncomeEntry),
    menuWindow(nullptr)
{
    ui->setupUi(this);

    // Connect the Return to Menu button to the slot
    connect(ui->returnToMenuButton, &QPushButton::clicked, this, &IncomeEntry::onReturnToMenuButtonClicked);
}

IncomeEntry::~IncomeEntry()
{
    delete ui;
    if (menuWindow) {
        delete menuWindow;
    }
}

void IncomeEntry::onReturnToMenuButtonClicked()
{
    if (!menuWindow) {
        menuWindow = new MenuWindow();
    }
    menuWindow->show();
    this->hide(); // Hide the IncomeEntry window
}
