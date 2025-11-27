#include "loginpage.h"
#include "ui_loginpage.h"
#include <QStandardPaths>
#include <QCoreApplication>
#include <QDir>
#include <QMovie>

static QString usersFilePath()
{
    QString baseDir = QCoreApplication::applicationDirPath();
    QString dir = baseDir + "/new/prefix1";

    QDir qdir;
    if (!qdir.mkpath(dir)) {
        qDebug() << "ERROR: Could not create directory" << dir;
    }

    QString path = dir + "/users.txt";
    qDebug() << "usersFilePath =" << path;
    return path;
}

loginpage::loginpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginpage)
{
    ui->setupUi(this);
    setWindowTitle("Login Page");
    QMovie *movie = new QMovie(":/new/prefix1/cute_loader.gif", QByteArray(), this);
    movie->start();

    QSize originalSize = movie->currentImage().size();

    double scale = 0.5;
    QSize scaledSize(originalSize.width() * scale,
                     originalSize.height() * scale);

    movie->setScaledSize(scaledSize);


    ui->label_animation->setMinimumSize(scaledSize);
    ui->label_animation->setMaximumSize(scaledSize);
    ui->label_animation->setAlignment(Qt::AlignCenter);
    ui->label_animation->setScaledContents(true);
    ui->verticalLayout->setAlignment(ui->label_animation, Qt::AlignHCenter);



    ui->label_animation->setMovie(movie);
    loadInfo();

}

void loginpage::loadInfo()
{
    QFile file(usersFilePath());

    if (!file.exists()) {
        qDebug() << "users.txt does not exist yet, skipping load";
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for reading:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    u.clear();

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty())   continue;

        QStringList parts = line.split(':');
        if (parts.size() >= 3) {
            QString name = parts[0].trimmed();
            QString pass = parts[1].trimmed();
            int level=parts[2].trimmed().toInt();

            Users user(name, pass,level);
            u.push_back(user);

            qDebug() << "Loaded user:" << name << "password:" << pass<<"level:"<<level;
        }
    }

    file.close();
}


loginpage::~loginpage()
{
    delete ui;
}


void loginpage::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text().trimmed();
    QString password = ui->lineEdit_password->text();
    int level;
    qDebug() << "Trying login with username =" << username
             << "password =" << password;

    bool loginSuccessful = false;
    bool usernameExists = false;

    for (const Users &user : u) {
        qDebug() << "Checking user in vector:" << user.getUsername()
        << "stored pass =" << user.getPassword();

        if (user.getUsername() == username) {
            usernameExists = true;
            if (user.getPassword() == password) {
                loginSuccessful = true;
                level=user.getLevel();
                break;
            }
        }
    }

    if (loginSuccessful) {
        qDebug() << "Login success!";
        MainWindow *mainpage = new MainWindow(username,level);
        this->hide();
        mainpage->show();
    } else {
        qDebug() << "Login failed. usernameExists =" << usernameExists;
        if (usernameExists) {
            QMessageBox::warning(this, "Login Failed", "Incorrect password");
        } else {
            QMessageBox::warning(this, "Login Failed",
                                 "Username does not exist.\n Please create an account.");
        }
        ui->lineEdit_password->clear();
    }

}

void loginpage::on_pushButton_createAccount_clicked()
{
    signuppage signup(this);
    signup.exec();
    u.clear();
    loadInfo();
}
