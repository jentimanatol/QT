#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QString>

class UserLogin
{
public:
    int loginID;
    QString username;
    QString password;
    int accessLevel;  // 0 for user, 1 for developer, 2 for admin
    int userID;  // Foreign key reference to User

    UserLogin(int id, const QString &uname, const QString &pass, int access, int userId)
        : loginID(id), username(uname), password(pass), accessLevel(access), userID(userId) {}
};

#endif // USERLOGIN_H
