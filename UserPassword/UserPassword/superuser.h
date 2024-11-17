#ifndef SUPERUSER_H
#define SUPERUSER_H

#include "user.h"

class SuperUser : public User {
public:
    SuperUser(const std::string& username, const std::string& password);
    // Additional functionalities for SuperUser
};

#endif // SUPERUSER_H
