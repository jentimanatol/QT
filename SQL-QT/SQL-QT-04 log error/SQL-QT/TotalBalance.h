#ifndef TOTALBALANCE_H
#define TOTALBALANCE_H

#include <QWidget>
class MenuWindow; // Forward declaration

namespace Ui {
class TotalBalance;
}

class TotalBalance : public QWidget
{
    Q_OBJECT

public:
    explicit TotalBalance(QWidget *parent = nullptr);
    ~TotalBalance();

private slots:
    void onReturnToMenuButtonClicked();

private:
    Ui::TotalBalance *ui;
    MenuWindow *menuWindow; // Pointer to MenuWindow class
};

#endif // TOTALBALANCE_H
