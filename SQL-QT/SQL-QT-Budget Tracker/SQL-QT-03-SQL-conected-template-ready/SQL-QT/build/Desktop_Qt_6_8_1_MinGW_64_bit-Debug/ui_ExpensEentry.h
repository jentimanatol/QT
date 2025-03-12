/********************************************************************************
** Form generated from reading UI file 'ExpensEentry.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENSEENTRY_H
#define UI_EXPENSEENTRY_H

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

class Ui_ExpenseEntry
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *categoryComboBox;
    QComboBox *subcategoryComboBox;
    QLineEdit *amountLineEdit;
    QLineEdit *descriptionLineEdit;
    QDateEdit *dateEdit;
    QPushButton *saveExpenseButton;
    QPushButton *returnToMenuButton;

    void setupUi(QWidget *ExpenseEntry)
    {
        if (ExpenseEntry->objectName().isEmpty())
            ExpenseEntry->setObjectName("ExpenseEntry");
        ExpenseEntry->resize(800, 600);
        verticalLayout = new QVBoxLayout(ExpenseEntry);
        verticalLayout->setObjectName("verticalLayout");
        categoryComboBox = new QComboBox(ExpenseEntry);
        categoryComboBox->setObjectName("categoryComboBox");

        verticalLayout->addWidget(categoryComboBox);

        subcategoryComboBox = new QComboBox(ExpenseEntry);
        subcategoryComboBox->setObjectName("subcategoryComboBox");

        verticalLayout->addWidget(subcategoryComboBox);

        amountLineEdit = new QLineEdit(ExpenseEntry);
        amountLineEdit->setObjectName("amountLineEdit");

        verticalLayout->addWidget(amountLineEdit);

        descriptionLineEdit = new QLineEdit(ExpenseEntry);
        descriptionLineEdit->setObjectName("descriptionLineEdit");

        verticalLayout->addWidget(descriptionLineEdit);

        dateEdit = new QDateEdit(ExpenseEntry);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(0, 0, 0));

        verticalLayout->addWidget(dateEdit);

        saveExpenseButton = new QPushButton(ExpenseEntry);
        saveExpenseButton->setObjectName("saveExpenseButton");

        verticalLayout->addWidget(saveExpenseButton);

        returnToMenuButton = new QPushButton(ExpenseEntry);
        returnToMenuButton->setObjectName("returnToMenuButton");

        verticalLayout->addWidget(returnToMenuButton);


        retranslateUi(ExpenseEntry);

        QMetaObject::connectSlotsByName(ExpenseEntry);
    } // setupUi

    void retranslateUi(QWidget *ExpenseEntry)
    {
        ExpenseEntry->setWindowTitle(QCoreApplication::translate("ExpenseEntry", "Expense Entry", nullptr));
        categoryComboBox->setPlaceholderText(QCoreApplication::translate("ExpenseEntry", "Select Category", nullptr));
        subcategoryComboBox->setPlaceholderText(QCoreApplication::translate("ExpenseEntry", "Select Subcategory", nullptr));
        amountLineEdit->setPlaceholderText(QCoreApplication::translate("ExpenseEntry", "Amount", nullptr));
        descriptionLineEdit->setPlaceholderText(QCoreApplication::translate("ExpenseEntry", "Description", nullptr));
        saveExpenseButton->setText(QCoreApplication::translate("ExpenseEntry", "Save Expense", nullptr));
        returnToMenuButton->setText(QCoreApplication::translate("ExpenseEntry", "Return to Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpenseEntry: public Ui_ExpenseEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENSEENTRY_H
