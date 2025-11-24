#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H
#include <QFile>
#include <QDialog>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include "users.h"

namespace Ui {
class signuppage;
}

class signuppage : public QDialog
{
    Q_OBJECT

public:
    explicit signuppage(QWidget *parent = nullptr);
    void loadInfo();
    ~signuppage();

private slots:

    void on_pushButton_signup_clicked();

private:
    Ui::signuppage *ui;
    QVector <Users> u;
};

#endif // SIGNUPPAGE_H
