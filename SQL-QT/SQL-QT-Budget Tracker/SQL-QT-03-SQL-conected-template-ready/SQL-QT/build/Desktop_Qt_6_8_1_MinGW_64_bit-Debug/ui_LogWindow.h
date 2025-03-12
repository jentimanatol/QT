/********************************************************************************
** Form generated from reading UI file 'LogWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWindow
{
public:
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonLogin;

    void setupUi(QWidget *LogWindow)
    {
        if (LogWindow->objectName().isEmpty())
            LogWindow->setObjectName("LogWindow");
        LogWindow->resize(800, 600);
        labelEmail = new QLabel(LogWindow);
        labelEmail->setObjectName("labelEmail");
        labelEmail->setGeometry(QRect(40, 100, 100, 20));
        lineEditEmail = new QLineEdit(LogWindow);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setGeometry(QRect(150, 100, 200, 20));
        labelPassword = new QLabel(LogWindow);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(40, 150, 100, 20));
        lineEditPassword = new QLineEdit(LogWindow);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(150, 150, 200, 20));
        lineEditPassword->setEchoMode(QLineEdit::Password);
        pushButtonLogin = new QPushButton(LogWindow);
        pushButtonLogin->setObjectName("pushButtonLogin");
        pushButtonLogin->setGeometry(QRect(150, 200, 75, 24));

        retranslateUi(LogWindow);

        QMetaObject::connectSlotsByName(LogWindow);
    } // setupUi

    void retranslateUi(QWidget *LogWindow)
    {
        LogWindow->setWindowTitle(QCoreApplication::translate("LogWindow", "Login", nullptr));
        labelEmail->setText(QCoreApplication::translate("LogWindow", "Email:", nullptr));
        labelPassword->setText(QCoreApplication::translate("LogWindow", "Password:", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("LogWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWindow: public Ui_LogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
