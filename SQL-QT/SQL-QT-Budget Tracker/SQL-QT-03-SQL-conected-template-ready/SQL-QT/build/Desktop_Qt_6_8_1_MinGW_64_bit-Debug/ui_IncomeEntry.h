/********************************************************************************
** Form generated from reading UI file 'IncomeEntry.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOMEENTRY_H
#define UI_INCOMEENTRY_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IncomeEntry
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *sourceComboBox;
    QLineEdit *amountLineEdit;
    QLineEdit *descriptionLineEdit;
    QDateEdit *dateEdit;
    QPushButton *saveIncomeButton;
    QPushButton *returnToMenuButton;

    void setupUi(QWidget *IncomeEntry)
    {
        if (IncomeEntry->objectName().isEmpty())
            IncomeEntry->setObjectName("IncomeEntry");
        IncomeEntry->resize(800, 600);
        verticalLayout = new QVBoxLayout(IncomeEntry);
        verticalLayout->setObjectName("verticalLayout");
        sourceComboBox = new QComboBox(IncomeEntry);
        sourceComboBox->setObjectName("sourceComboBox");

        verticalLayout->addWidget(sourceComboBox);

        amountLineEdit = new QLineEdit(IncomeEntry);
        amountLineEdit->setObjectName("amountLineEdit");

        verticalLayout->addWidget(amountLineEdit);

        descriptionLineEdit = new QLineEdit(IncomeEntry);
        descriptionLineEdit->setObjectName("descriptionLineEdit");

        verticalLayout->addWidget(descriptionLineEdit);

        dateEdit = new QDateEdit(IncomeEntry);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(0, 0, 0));

        verticalLayout->addWidget(dateEdit);

        saveIncomeButton = new QPushButton(IncomeEntry);
        saveIncomeButton->setObjectName("saveIncomeButton");

        verticalLayout->addWidget(saveIncomeButton);

        returnToMenuButton = new QPushButton(IncomeEntry);
        returnToMenuButton->setObjectName("returnToMenuButton");

        verticalLayout->addWidget(returnToMenuButton);


        retranslateUi(IncomeEntry);

        QMetaObject::connectSlotsByName(IncomeEntry);
    } // setupUi

    void retranslateUi(QWidget *IncomeEntry)
    {
        IncomeEntry->setWindowTitle(QCoreApplication::translate("IncomeEntry", "Income Entry", nullptr));
        sourceComboBox->setPlaceholderText(QCoreApplication::translate("IncomeEntry", "Select Source", nullptr));
        amountLineEdit->setPlaceholderText(QCoreApplication::translate("IncomeEntry", "Amount", nullptr));
        descriptionLineEdit->setPlaceholderText(QCoreApplication::translate("IncomeEntry", "Description", nullptr));
        saveIncomeButton->setText(QCoreApplication::translate("IncomeEntry", "Save Income", nullptr));
        returnToMenuButton->setText(QCoreApplication::translate("IncomeEntry", "Return to Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IncomeEntry: public Ui_IncomeEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOMEENTRY_H
