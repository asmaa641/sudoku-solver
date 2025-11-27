#ifndef USERS_H
#define USERS_H

#include <QString>

class Users
{
private:
    QString username;
    QString password;
    int level;

public:
    Users();
    Users(const QString &u, const QString &p, const int &l);

    QString getUsername() const;
    QString getPassword() const;
    int getLevel() const;

    void setUsername(const QString &u);
    void setPassword(const QString &p);
    void setLevel(const int &l);
};

#endif // USERS_H
