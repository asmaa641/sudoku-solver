#include "signuppage.h"
#include "ui_signuppage.h"

signuppage::signuppage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signuppage)
{
    ui->setupUi(this);
   setWindowTitle("Sign Up Page");
    loadInfo();
}

void signuppage::loadInfo()
{
    QFile file(":/new/prefix1/users.txt");
    QTextStream in(&file);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!file.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(':');

            if (parts.size() >= 2) {
                // Convert QString to std::string
                Users u1(parts[0], parts[1]);
                u.push_back(u1);
            }
        }
    }
    else{
        qDebug()<<"Could not open file";
    }
    file.close();
}

signuppage::~signuppage()
{
    QFile file(":/new/prefix1/users.txt");
    QTextStream out(&file);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        for (Users& user : u) {
            out<<user.getUsername()<<":"<<user.getPassword();
        }
    }
    delete ui;

}


void signuppage::on_pushButton_signup_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    // Search for user in the vector
    bool successful = false;
    bool usernameExists = false;

    for (Users& user : u) {
        if (user.getUsername() == username) {
            usernameExists = true;
        }
        else{
            successful=true;
        }
    }

    if(usernameExists){
        QMessageBox::warning(this, "SignUp failed", "Username already exist. \n Please try another one");
    }
    if(successful){
        Users u1(username, password);
        u.push_back(u1);
        QMessageBox::information(this,"Successful Account Creation","Your account has been created");
        this->close();
    }
}

