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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_loginpage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *label_animation;
    QLabel *subtitleLabel;
    QFormLayout *formLayout;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QLabel *label;
    QLineEdit *lineEdit_password;
    QHBoxLayout *bottomLayout;
    QLabel *label_2;
    QPushButton *pushButton_createAccount;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_login;

    void setupUi(QDialog *loginpage)
    {
        if (loginpage->objectName().isEmpty())
            loginpage->setObjectName("loginpage");
        loginpage->resize(581, 429);
        loginpage->setStyleSheet(QString::fromUtf8("QDialog#loginpage {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #ffe4f7,  \n"
"        stop:1 #dbeafe   \n"
"    );\n"
"    font-family: \"Segoe UI\", \"SF Pro Text\", system-ui;\n"
"}\n"
"\n"
"QLabel {\n"
"\n"
"    color: #4b5563;  \n"
"}\n"
"\n"
"QLabel#label_2 {\n"
"    color: #6b7280;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 6px 10px;\n"
"    border-radius: 12px;\n"
"    border: 1px solid #f9a8d4;  \n"
"    background-color: #ffffff;\n"
"    color: #374151;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #f973ab;   \n"
"    background-color: #fff7fb;\n"
"}\n"
"\n"
"QPushButton#pushButton_login {\n"
"    background-color: #f973ab;   \n"
"    color: #ffffff;\n"
"    border-radius: 16px;\n"
"    padding: 6px 18px;\n"
"    font-weight: 600;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#pushButton_login:hover {\n"
"    background-color: #fb7185;   \n"
"}\n"
"\n"
"QPushButton#pushButton_login:pressed {\n"
"    background-co"
                        "lor: #f43f5e;\n"
"}\n"
"\n"
"QPushButton#pushButton_createAccount {\n"
"    background-color: #e0e7ff;   \n"
"    color: #4c1d95;            \n"
"    border-radius: 16px;\n"
"    padding: 6px 14px;\n"
"    border: 1px solid #c4b5fd;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QPushButton#pushButton_createAccount:hover {\n"
"    background-color: #c7d2fe;\n"
"}\n"
"\n"
"QPushButton {\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(loginpage);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(loginpage);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setPointSize(34);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        label_animation = new QLabel(loginpage);
        label_animation->setObjectName("label_animation");
        label_animation->setMaximumSize(QSize(1000, 1000));
        label_animation->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_animation->setMargin(7);

        verticalLayout->addWidget(label_animation);

        subtitleLabel = new QLabel(loginpage);
        subtitleLabel->setObjectName("subtitleLabel");
        QFont font1;
        font1.setPointSize(17);
        subtitleLabel->setFont(font1);
        subtitleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(subtitleLabel);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_username = new QLabel(loginpage);
        label_username->setObjectName("label_username");
        QFont font2;
        font2.setBold(true);
        label_username->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_username);

        lineEdit_username = new QLineEdit(loginpage);
        lineEdit_username->setObjectName("lineEdit_username");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_username);

        label = new QLabel(loginpage);
        label->setObjectName("label");
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        label->setFont(font3);

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        lineEdit_password = new QLineEdit(loginpage);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_password);


        verticalLayout->addLayout(formLayout);

        bottomLayout = new QHBoxLayout();
        bottomLayout->setObjectName("bottomLayout");
        label_2 = new QLabel(loginpage);
        label_2->setObjectName("label_2");

        bottomLayout->addWidget(label_2);

        pushButton_createAccount = new QPushButton(loginpage);
        pushButton_createAccount->setObjectName("pushButton_createAccount");

        bottomLayout->addWidget(pushButton_createAccount);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        bottomLayout->addItem(horizontalSpacer);

        pushButton_login = new QPushButton(loginpage);
        pushButton_login->setObjectName("pushButton_login");

        bottomLayout->addWidget(pushButton_login);


        verticalLayout->addLayout(bottomLayout);


        retranslateUi(loginpage);

        QMetaObject::connectSlotsByName(loginpage);
    } // setupUi

    void retranslateUi(QDialog *loginpage)
    {
        loginpage->setWindowTitle(QCoreApplication::translate("loginpage", "Login", nullptr));
        titleLabel->setText(QCoreApplication::translate("loginpage", "Welcome!", nullptr));
        label_animation->setText(QString());
        subtitleLabel->setText(QCoreApplication::translate("loginpage", "Sign in to continue to Sudoku Solver", nullptr));
        label_username->setText(QCoreApplication::translate("loginpage", "Username:", nullptr));
        label->setText(QCoreApplication::translate("loginpage", "Password:", nullptr));
        lineEdit_password->setText(QString());
        label_2->setText(QCoreApplication::translate("loginpage", "Don't have an account? ", nullptr));
        pushButton_createAccount->setText(QCoreApplication::translate("loginpage", "Create Account", nullptr));
        pushButton_login->setText(QCoreApplication::translate("loginpage", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginpage: public Ui_loginpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
