#ifndef LOGINPAGE_H
#define LOGINPAGE_H
#include "mainwindow.h"
#include <QVector>
#include <QFile>
#include <string.h>
#include <QDialog>
#include <QMessageBox>
using namespace std;

struct users{
    QString username;
    QString password;
     users(QString s, QString p){
        username=s;
        password=p;
    }
};

namespace Ui {
class loginpage;
}

class loginpage : public QDialog
{
    Q_OBJECT

public:
    explicit loginpage(QWidget *parent = nullptr);
    ~loginpage();

private slots:

    void on_pushButton_login_clicked();

private:
    Ui::loginpage *ui;
    QVector <users> u;
};

#endif // LOGINPAGE_H
