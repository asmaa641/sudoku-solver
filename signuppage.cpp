#include "signuppage.h"
#include "ui_signuppage.h"
#include <QStandardPaths>
#include <QDir>

static QString usersFilePath()
{
    QString dir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dir);              // make sure the folder exists
    return dir + "/users.txt";       // final path: something like .../YourApp/users.txt
}

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
    QFile file(usersFilePath());
    QTextStream in(&file);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!file.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(':');

            if (parts.size() >= 2) {
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
    delete ui;
}


void signuppage::on_pushButton_signup_clicked()
{
    QString username = ui->lineEdit_username->text().trimmed();
    QString password = ui->lineEdit_password->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Sign Up failed",
                             "Username and password cannot be empty.");
        return;
    }

    bool usernameExists = false;

    for (Users &user : u) {
        if (user.getUsername() == username) {
            usernameExists = true;
            break;
        }
    }

    if (usernameExists) {
        QMessageBox::warning(this, "Sign Up failed",
                             "Username already exists.\nPlease try another one.");
        return;
    }

    // Add user to the in-memory list
    Users u1(username, password);
    u.push_back(u1);

    // Append to the file on disk
    QFile file(usersFilePath());
    qDebug()<<"right before if";
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        qDebug()<<"in if";
        out << username << ":" << password << "\n";  // NOTE the newline
    } else {
        QMessageBox::warning(this, "Error",
                             "Could not save account to file.");
    }

    QMessageBox::information(this, "Successful Account Creation",
                             "Your account has been created");
    close();
}


