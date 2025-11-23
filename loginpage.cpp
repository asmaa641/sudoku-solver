#include "loginpage.h"
#include "ui_loginpage.h"

loginpage::loginpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginpage)
{
    ui->setupUi(this);
    QFile file("/Users/jojo/Desktop/Sudoko_solver/users.txt");
    QTextStream in(&file);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!file.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(':');

            if (parts.size() >= 2) {
                // Convert QString to std::string
                users u1(parts[0], parts[1]);
                u.push_back(u1);
        }
        }
    }
    else{
        qDebug()<<"Could not open file";
    }

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
    for (const users& user : u) {
        if (user.username == username && user.password == password) {
            loginSuccessful = true;
            break;
        }
    }

    if (loginSuccessful) {
        MainWindow *mainpage = new MainWindow();
        this->hide();
        mainpage->show();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password");
        ui->lineEdit_password->clear();// Clear password field for security

    }

}

