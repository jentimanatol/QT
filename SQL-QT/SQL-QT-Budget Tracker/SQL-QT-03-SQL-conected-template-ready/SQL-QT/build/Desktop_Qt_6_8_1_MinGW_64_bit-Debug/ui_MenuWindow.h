/********************************************************************************
** Form generated from reading UI file 'MenuWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QVBoxLayout *verticalLayout_menu;
    QLabel *bannerLabel;
    QLabel *userLastNameLabel;
    QPushButton *incomeButton;
    QPushButton *expenseButton;
    QPushButton *totalButton;
    QPushButton *logoutButton;

    void setupUi(QWidget *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName("MenuWindow");
        MenuWindow->resize(800, 600);
        verticalLayout_menu = new QVBoxLayout(MenuWindow);
        verticalLayout_menu->setObjectName("verticalLayout_menu");
        bannerLabel = new QLabel(MenuWindow);
        bannerLabel->setObjectName("bannerLabel");
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        bannerLabel->setFont(font);
        bannerLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_menu->addWidget(bannerLabel);

        userLastNameLabel = new QLabel(MenuWindow);
        userLastNameLabel->setObjectName("userLastNameLabel");
        QFont font1;
        font1.setPointSize(18);
        userLastNameLabel->setFont(font1);

        verticalLayout_menu->addWidget(userLastNameLabel);

        incomeButton = new QPushButton(MenuWindow);
        incomeButton->setObjectName("incomeButton");

        verticalLayout_menu->addWidget(incomeButton);

        expenseButton = new QPushButton(MenuWindow);
        expenseButton->setObjectName("expenseButton");

        verticalLayout_menu->addWidget(expenseButton);

        totalButton = new QPushButton(MenuWindow);
        totalButton->setObjectName("totalButton");

        verticalLayout_menu->addWidget(totalButton);

        logoutButton = new QPushButton(MenuWindow);
        logoutButton->setObjectName("logoutButton");

        verticalLayout_menu->addWidget(logoutButton);


        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QWidget *MenuWindow)
    {
        MenuWindow->setWindowTitle(QCoreApplication::translate("MenuWindow", "Menu", nullptr));
        bannerLabel->setText(QCoreApplication::translate("MenuWindow", "Welcome to the Menu", nullptr));
        userLastNameLabel->setText(QCoreApplication::translate("MenuWindow", "Last Name: ", nullptr));
        incomeButton->setText(QCoreApplication::translate("MenuWindow", "Income", nullptr));
        expenseButton->setText(QCoreApplication::translate("MenuWindow", "Expense", nullptr));
        totalButton->setText(QCoreApplication::translate("MenuWindow", "Total", nullptr));
        logoutButton->setText(QCoreApplication::translate("MenuWindow", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
