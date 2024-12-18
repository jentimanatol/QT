#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "LogWindow.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onStartButtonClicked();

private:
    Ui::Widget *ui;
    LogWindow *logWindow;
};

#endif // WIDGET_H
