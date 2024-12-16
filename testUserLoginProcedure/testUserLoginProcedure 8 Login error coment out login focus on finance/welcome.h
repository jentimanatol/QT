#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();

private slots:
    void onIncomeEntryButtonClicked();
    void onExpenseEntryButtonClicked();
    void onTotalBalanceButtonClicked();

private:
    Ui::Welcome *ui;
    QSqlDatabase db;
};

#endif // WELCOME_H
