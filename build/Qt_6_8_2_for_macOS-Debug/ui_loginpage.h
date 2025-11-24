/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginpage
{
public:
    QPushButton *pushButton_login;
    QPushButton *pushButton_createAccount;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLabel *label_username;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *loginpage)
    {
        if (loginpage->objectName().isEmpty())
            loginpage->setObjectName("loginpage");
        loginpage->setEnabled(true);
        loginpage->resize(990, 641);
        pushButton_login = new QPushButton(loginpage);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(520, 370, 111, 31));
        pushButton_createAccount = new QPushButton(loginpage);
        pushButton_createAccount->setObjectName("pushButton_createAccount");
        pushButton_createAccount->setEnabled(true);
        pushButton_createAccount->setGeometry(QRect(300, 370, 121, 31));
        lineEdit_username = new QLineEdit(loginpage);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(500, 160, 113, 21));
        lineEdit_password = new QLineEdit(loginpage);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(500, 230, 113, 21));
        label_username = new QLabel(loginpage);
        label_username->setObjectName("label_username");
        label_username->setGeometry(QRect(310, 160, 111, 20));
        label = new QLabel(loginpage);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 240, 91, 16));
        label_2 = new QLabel(loginpage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 320, 341, 21));

        retranslateUi(loginpage);

        QMetaObject::connectSlotsByName(loginpage);
    } // setupUi

    void retranslateUi(QDialog *loginpage)
    {
        loginpage->setWindowTitle(QCoreApplication::translate("loginpage", "Dialog", nullptr));
        pushButton_login->setText(QCoreApplication::translate("loginpage", "Login", nullptr));
        pushButton_createAccount->setText(QCoreApplication::translate("loginpage", "Create Account", nullptr));
        label_username->setText(QCoreApplication::translate("loginpage", "Username:", nullptr));
        label->setText(QCoreApplication::translate("loginpage", "Password:", nullptr));
        label_2->setText(QCoreApplication::translate("loginpage", "Don't have an account? Sign Up :)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginpage: public Ui_loginpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
