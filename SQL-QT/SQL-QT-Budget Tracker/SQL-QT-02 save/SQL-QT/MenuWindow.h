#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include "IncomeEntry.h"
#include "ExpenseEntry.h"
#include "TotalBalance.h"
#include "LogWindow.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void onIncomeButtonClicked();
    void onExpenseButtonClicked();
    void onTotalButtonClicked();
    void onLogoutButtonClicked();

private:
    Ui::MenuWindow *ui;
    IncomeEntry *incomeEntryWindow;
    ExpenseEntry *expenseEntryWindow;
    TotalBalance *totalBalanceWindow;
    LogWindow *logWindow;
};

#endif // MENUWINDOW_H
