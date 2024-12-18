#include "totalbalance.h"
#include "ui_totalbalance.h"

TotalBalance::TotalBalance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TotalBalance)
{
    ui->setupUi(this);
}

TotalBalance::~TotalBalance
