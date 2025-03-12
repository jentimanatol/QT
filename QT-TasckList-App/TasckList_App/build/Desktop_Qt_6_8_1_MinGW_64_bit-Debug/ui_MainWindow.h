/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *toolbarLayout;
    QLabel *lblStatus;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAddTask;
    QVBoxLayout *tasksLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(631, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        toolbarLayout = new QHBoxLayout();
        toolbarLayout->setObjectName("toolbarLayout");
        lblStatus = new QLabel(centralwidget);
        lblStatus->setObjectName("lblStatus");

        toolbarLayout->addWidget(lblStatus);

        horizontalSpacer = new QSpacerItem(779, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        toolbarLayout->addItem(horizontalSpacer);

        btnAddTask = new QPushButton(centralwidget);
        btnAddTask->setObjectName("btnAddTask");

        toolbarLayout->addWidget(btnAddTask);


        verticalLayout->addLayout(toolbarLayout);

        tasksLayout = new QVBoxLayout();
        tasksLayout->setObjectName("tasksLayout");

        verticalLayout->addLayout(tasksLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "To Do List", nullptr));
        lblStatus->setText(QCoreApplication::translate("MainWindow", "Status: 0 todo / 0 done", nullptr));
        btnAddTask->setText(QCoreApplication::translate("MainWindow", "Add Task", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
