#ifndef INCOMEENTRY_H
#define INCOMEENTRY_H

#include <QWidget>
class MenuWindow; // Forward declaration

namespace Ui {
class IncomeEntry;
}

class IncomeEntry : public QWidget
{
    Q_OBJECT

public:
    explicit IncomeEntry(QWidget *parent = nullptr);
    ~IncomeEntry();

private slots:
    void onReturnToMenuButtonClicked();

private:
    Ui::IncomeEntry *ui;
    MenuWindow *menuWindow; // Pointer to MenuWindow class
};

#endif // INCOMEENTRY_H
