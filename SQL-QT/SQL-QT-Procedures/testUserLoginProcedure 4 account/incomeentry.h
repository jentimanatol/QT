#ifndef INCOMEENTRY_H
#define INCOMEENTRY_H

#include <QWidget>

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
    void onSaveIncomeButtonClicked();

private:
    Ui::IncomeEntry *ui;
};

#endif // INCOMEENTRY_H
