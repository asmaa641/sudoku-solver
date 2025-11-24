#ifndef USERS_H
#define USERS_H
#include <QString>
#include <QFile>
#include <QTextStream>
class Users
{
public:
    Users(QString s, QString p);
    QString getUsername();
    QString getPassword();

private:
    QString username;
    QString password;
    QString level;
};

#endif // USERS_H
