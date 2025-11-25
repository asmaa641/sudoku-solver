#include "users.h"

Users::Users()
    : username(), password()
{
}

Users::Users(const QString &u, const QString &p)
    : username(u), password(p)
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

void Users::setUsername(const QString &u)
{
    username = u;
}

void Users::setPassword(const QString &p)
{
    password = p;
}
