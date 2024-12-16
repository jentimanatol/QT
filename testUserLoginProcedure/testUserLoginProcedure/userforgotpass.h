#ifndef USERFORGOTPASS_H
#define USERFORGOTPASS_H

#include <QWidget>

namespace Ui {
class UserForgotPass;
}

class UserForgotPass : public QWidget
{
    Q_OBJECT

public:
    explicit UserForgotPass(QWidget *parent = nullptr);
    ~UserForgotPass();

private slots:
    void onForgotPasswordButtonClicked();

private:
    Ui::UserForgotPass *ui;
    void executeForgotPasswordProcedure(const QString &username, const QString &newPassword);
};

#endif // USERFORGOTPASS_H
