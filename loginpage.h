#ifndef LOGINPAGE_H
#define LOGINPAGE_H
#include "mainwindow.h"
#include "signuppage.h"
#include <string.h>
#include <QDialog>
using namespace std;


namespace Ui {
class loginpage;
}

class loginpage : public QDialog
{
    Q_OBJECT

public:
    explicit loginpage(QWidget *parent = nullptr);
    void loadInfo();
    ~loginpage();

private slots:

    void on_pushButton_login_clicked();

    void on_pushButton_createAccount_clicked();

private:
    Ui::loginpage *ui;
    QVector <Users> u;
};

#endif // LOGINPAGE_H
