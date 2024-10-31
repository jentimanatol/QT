/********************************************************************************
** Form generated from reading UI file 'expense.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENSE_H
#define UI_EXPENSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Expense
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Expense)
    {
        if (Expense->objectName().isEmpty())
            Expense->setObjectName("Expense");
        Expense->resize(800, 600);
        centralwidget = new QWidget(Expense);
        centralwidget->setObjectName("centralwidget");
        Expense->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Expense);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Expense->setMenuBar(menubar);
        statusbar = new QStatusBar(Expense);
        statusbar->setObjectName("statusbar");
        Expense->setStatusBar(statusbar);

        retranslateUi(Expense);

        QMetaObject::connectSlotsByName(Expense);
    } // setupUi

    void retranslateUi(QMainWindow *Expense)
    {
        Expense->setWindowTitle(QCoreApplication::translate("Expense", "Expense", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Expense: public Ui_Expense {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENSE_H
