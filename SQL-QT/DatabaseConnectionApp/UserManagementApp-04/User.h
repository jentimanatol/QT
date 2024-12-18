#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    int userID;
    QString firstname;
    QString lastname;
    QString position;

    User(int id, const QString &fName, const QString &lName, const QString &pos)
        : userID(id), firstname(fName), lastname(lName), position(pos) {}
};

#endif // USER_H
