#include "signuppage.h"
#include "ui_signuppage.h"
#include <QCoreApplication>
#include <QStandardPaths>
#include <QDir>

static QString usersFilePath()
{
    // Directory where the .exe / .app binary lives
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
        if (line.isEmpty())
            continue;

        QStringList parts = line.split(':');
        if (parts.size() >= 3) {
            QString name = parts[0].trimmed();
            QString pass = parts[1].trimmed();
            int level=parts[2].trimmed().toInt();

            Users user(name, pass,level);
            u.push_back(user);

            qDebug() << "Loaded user:" << name << "password:" << pass<< "level:" << level;
        }
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
    Users u1(username, password,0);
    u.push_back(u1);

    // Append to the file on disk
    QFile file(usersFilePath());
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << username << ":" << password << ":"<<0<<"\n";  // NOTE the newline
    } else {
        QMessageBox::warning(this, "Error",
                             "Could not save account to file.");
    }

    QMessageBox::information(this, "Successful Account Creation",
                             "Your account has been created");
    close();
}

