#ifndef TOTALBALANCE_H
#define TOTALBALANCE_H

#include <QWidget>

namespace Ui {
class TotalBalance;
}

class TotalBalance : public QWidget
{
    Q_OBJECT

public:
    explicit TotalBalance(QWidget *parent = nullptr);
    ~TotalBalance();

private:
    Ui::TotalBalance *ui;
};

#endif // TOTALBALANCE_H
