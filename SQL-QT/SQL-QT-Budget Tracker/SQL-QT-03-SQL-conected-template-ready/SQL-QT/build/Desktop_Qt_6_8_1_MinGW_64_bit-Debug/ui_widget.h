/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButtonStart;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        pushButtonStart = new QPushButton(Widget);
        pushButtonStart->setObjectName("pushButtonStart");
        pushButtonStart->setGeometry(QRect(280, 350, 181, 61));
        QFont font;
        font.setPointSize(29);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setKerning(true);
        pushButtonStart->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 150, 271, 131));
        QFont font1;
        font1.setPointSize(13);
        label->setFont(font1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("Widget", "START", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Welcome to Budget Tracking App", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
