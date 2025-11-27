/********************************************************************************
** Form generated from reading UI file 'signuppage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPPAGE_H
#define UI_SIGNUPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_signuppage
{
public:
    QLabel *label_info;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_signup;
    QLabel *label;

    void setupUi(QDialog *signuppage)
    {
        if (signuppage->objectName().isEmpty())
            signuppage->setObjectName("signuppage");
        signuppage->resize(682, 796);
        label_info = new QLabel(signuppage);
        label_info->setObjectName("label_info");
        label_info->setGeometry(QRect(170, 120, 371, 31));
        lineEdit_username = new QLineEdit(signuppage);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(330, 190, 151, 31));
        lineEdit_password = new QLineEdit(signuppage);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(330, 260, 151, 31));
        label_2 = new QLabel(signuppage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 190, 111, 16));
        label_3 = new QLabel(signuppage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 260, 111, 16));
        pushButton_signup = new QPushButton(signuppage);
        pushButton_signup->setObjectName("pushButton_signup");
        pushButton_signup->setGeometry(QRect(280, 370, 100, 32));
        label = new QLabel(signuppage);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 320, 471, 16));

        retranslateUi(signuppage);

        QMetaObject::connectSlotsByName(signuppage);
    } // setupUi

    void retranslateUi(QDialog *signuppage)
    {
        signuppage->setWindowTitle(QCoreApplication::translate("signuppage", "Dialog", nullptr));
        label_info->setText(QCoreApplication::translate("signuppage", "Please insert your desired username and password:", nullptr));
        label_2->setText(QCoreApplication::translate("signuppage", "Username:", nullptr));
        label_3->setText(QCoreApplication::translate("signuppage", "Password:", nullptr));
        pushButton_signup->setText(QCoreApplication::translate("signuppage", "SignUp", nullptr));
        label->setText(QCoreApplication::translate("signuppage", "Note: If signingup is successful window will automatically close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signuppage: public Ui_signuppage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPPAGE_H
