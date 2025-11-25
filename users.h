#ifndef USERS_H
#define USERS_H

#include <QString>

class Users
{
private:
    QString username;
    QString password;

public:
    Users();
    Users(const QString &u, const QString &p);

    QString getUsername() const;
    QString getPassword() const;

    void setUsername(const QString &u);
    void setPassword(const QString &p);
};

#endif // USERS_H
