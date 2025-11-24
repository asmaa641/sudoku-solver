#include "users.h"

Users::Users(QString s, QString p){
        username=s;
        password=p;
}

QString Users::getPassword(){
    return password;
}
QString Users::getUsername(){
    return username;
}
