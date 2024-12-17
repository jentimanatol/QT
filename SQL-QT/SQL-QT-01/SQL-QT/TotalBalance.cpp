#include "TotalBalance.h"
#include "ui_TotalBalance.h"
#include "MenuWindow.h" // Include the MenuWindow header

TotalBalance::TotalBalance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TotalBalance),
    menuWindow(nullptr)
{
    ui->setupUi(this);

    // Connect the Return to Menu button to the slot
    connect(ui->returnToMenuButton, &QPushButton::clicked, this, &TotalBalance::onReturnToMenuButtonClicked);
}

TotalBalance::~TotalBalance()
{
    delete ui;
    if (menuWindow) {
        delete menuWindow;
    }
}

void TotalBalance::onReturnToMenuButtonClicked()
{
    if (!menuWindow) {
        menuWindow = new MenuWindow();
    }
    menuWindow->show();
    this->hide(); // Hide the TotalBalance window
}
