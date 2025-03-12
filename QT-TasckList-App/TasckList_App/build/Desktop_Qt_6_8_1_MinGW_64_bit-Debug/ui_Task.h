/********************************************************************************
** Form generated from reading UI file 'Task.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnEdit;
    QPushButton *btnRemove;

    void setupUi(QWidget *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName("Task");
        Task->resize(599, 300);
        horizontalLayout = new QHBoxLayout(Task);
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox = new QCheckBox(Task);
        checkBox->setObjectName("checkBox");

        horizontalLayout->addWidget(checkBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnEdit = new QPushButton(Task);
        btnEdit->setObjectName("btnEdit");

        horizontalLayout->addWidget(btnEdit);

        btnRemove = new QPushButton(Task);
        btnRemove->setObjectName("btnRemove");

        horizontalLayout->addWidget(btnRemove);


        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QWidget *Task)
    {
        Task->setWindowTitle(QCoreApplication::translate("Task", "Form", nullptr));
        checkBox->setText(QCoreApplication::translate("Task", "CheckBox", nullptr));
        btnEdit->setText(QCoreApplication::translate("Task", "Edit", nullptr));
        btnRemove->setText(QCoreApplication::translate("Task", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
