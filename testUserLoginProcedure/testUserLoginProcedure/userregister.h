#ifndef USERREGISTER_H
#define USERREGISTER_H

#include <QWidget>

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
    void executeRegisterProcedure(const QString &firstName, const QString &lastName, const QString &username, const QString &password, const QString &position);
};

#endif // USERREGISTER_H
