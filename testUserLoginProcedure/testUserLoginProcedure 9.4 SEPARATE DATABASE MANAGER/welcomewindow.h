#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui {class WelcomeWindow;}
QT_END_NAMESPACE



class WelcomeWindow : public QWidget
{
    Q_OBJECT



public:
    explicit WelcomeWindow(QWidget *parent = nullptr);

    ~WelcomeWindow();

    void setUserDetails(const QString &firstName, const QString &lastName, int userID);

private:
    Ui::WelcomeWindow *ui;




private slots:
    void onIncomeButtonClicked();
    void onExpenseButtonClicked();
    void onTotalButtonClicked();
};

#endif // WELCOMEWINDOW_H
