#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class loginwindow;
}
QT_END_NAMESPACE

class loginwindow : public QWidget
{
    Q_OBJECT

public:
    loginwindow(QWidget *parent = nullptr);
    ~loginwindow();

private:
    Ui::loginwindow *ui;
};
#endif // LOGINWINDOW_H
