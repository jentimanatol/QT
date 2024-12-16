#ifndef USERREGISTER_H
#define USERREGISTER_H

#include <QWidget>
#include <QString>

namespace Ui {
class UserRegister;
}

class UserRegister : public QWidget
{
    Q_OBJECT

public:
    explicit UserRegister(QWidget *parent = nullptr);
    ~UserRegister();

private slots:
    void onRegisterButtonClicked();

private:
    Ui::UserRegister *ui;
    void executeRegisterProcedure(const QString &firstName, const QString &lastName, const QString &email, const QString &password, const QString &city, const QString &country, const QString &phone);
};

#endif // USERREGISTER_H
