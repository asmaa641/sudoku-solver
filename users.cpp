#include "users.h"

Users::Users()
    : username(), password(),level()
{
}

Users::Users(const QString &u, const QString &p,const int &l)
    : username(u), password(p),level(l)
{
}

QString Users::getUsername() const
{
    return username;
}

QString Users::getPassword() const
{
    return password;
}

int Users::getLevel() const
{
    return level;
}

void Users::setUsername(const QString &u)
{
    username = u;
}

void Users::setPassword(const QString &p)
{
    password = p;
}

void Users::setLevel(const int &l)
{
    level=l;
}
