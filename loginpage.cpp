#include "loginpage.h"
#include "ui_loginpage.h"

loginpage::loginpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginpage)
{
    ui->setupUi(this);
    setWindowTitle("Login Page");
    loadInfo();
}

void loginpage::loadInfo()
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


loginpage::~loginpage()
{
    delete ui;
}


void loginpage::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    // Search for user in the vector
    bool loginSuccessful = false;
    bool usernameExists = false;

    for (Users& user : u) {
        if (user.getUsername() == username) {
            usernameExists = true;
            if (user.getPassword() == password) {
                loginSuccessful = true;
                break;
            }
        }
    }

    if (loginSuccessful) {
        MainWindow *mainpage = new MainWindow();
        this->hide();
        mainpage->show();
    } else {
        if (usernameExists) {
            QMessageBox::warning(this, "Login Failed", "Incorrect password");//username exists but the password is wrong
        } else {
            QMessageBox::warning(this, "Login Failed", "Username does not exist.\n Please create an account.");//username does not exist
        }
        ui->lineEdit_password->clear(); // Clear password field for security
    }
}


void loginpage::on_pushButton_createAccount_clicked()
{
    signuppage *signup = new signuppage();
    signup->exec();// This function will block until the signup window is closed.
    signup->show();
    u.clear();
    delete signup;
    loadInfo();
}

