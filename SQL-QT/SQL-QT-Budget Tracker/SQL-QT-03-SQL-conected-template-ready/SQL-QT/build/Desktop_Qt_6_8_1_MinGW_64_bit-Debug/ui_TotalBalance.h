/********************************************************************************
** Form generated from reading UI file 'TotalBalance.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTALBALANCE_H
#define UI_TOTALBALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TotalBalance
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *totalBalanceLabel;
    QPushButton *returnToMenuButton;

    void setupUi(QWidget *TotalBalance)
    {
        if (TotalBalance->objectName().isEmpty())
            TotalBalance->setObjectName("TotalBalance");
        TotalBalance->resize(800, 600);
        verticalLayout = new QVBoxLayout(TotalBalance);
        verticalLayout->setObjectName("verticalLayout");
        totalBalanceLabel = new QLabel(TotalBalance);
        totalBalanceLabel->setObjectName("totalBalanceLabel");
        totalBalanceLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(totalBalanceLabel);

        returnToMenuButton = new QPushButton(TotalBalance);
        returnToMenuButton->setObjectName("returnToMenuButton");

        verticalLayout->addWidget(returnToMenuButton);


        retranslateUi(TotalBalance);

        QMetaObject::connectSlotsByName(TotalBalance);
    } // setupUi

    void retranslateUi(QWidget *TotalBalance)
    {
        TotalBalance->setWindowTitle(QCoreApplication::translate("TotalBalance", "Total Balance", nullptr));
        totalBalanceLabel->setText(QCoreApplication::translate("TotalBalance", "Your total balance is: $0.00", nullptr));
        returnToMenuButton->setText(QCoreApplication::translate("TotalBalance", "Return to Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TotalBalance: public Ui_TotalBalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALBALANCE_H
