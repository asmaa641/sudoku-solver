/********************************************************************************
** Form generated from reading UI file 'signuppage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPPAGE_H
#define UI_SIGNUPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_signuppage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QLabel *label_info;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_username;
    QLabel *label_3;
    QLineEdit *lineEdit_password;
    QLabel *label_note;
    QHBoxLayout *buttonLayout;
    QPushButton *pushButton_signup;

    void setupUi(QDialog *signuppage)
    {
        if (signuppage->objectName().isEmpty())
            signuppage->setObjectName("signuppage");
        signuppage->resize(480, 360);
        signuppage->setStyleSheet(QString::fromUtf8("\n"
"QDialog#signuppage {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #ffe4f7,  \n"
"        stop:1 #dbeafe   \n"
"    );\n"
"    font-family: \"Segoe UI\", \"SF Pro Text\", system-ui;\n"
"}\n"
"\n"
"\n"
"QLabel {\n"
" \n"
"    color: #4b5563;\n"
"}\n"
"\n"
"QLabel#label_note {\n"
"    color: #6b7280;\n"
"}\n"
"\n"
"QLabel#label_2,\n"
"QLabel#label_3 {\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 6px 10px;\n"
"    border-radius: 12px;\n"
"    border: 1px solid #f9a8d4;\n"
"    background-color: #ffffff;\n"
"    color: #374151;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #f973ab;\n"
"    background-color: #fff7fb;\n"
"}\n"
"\n"
"QPushButton#pushButton_signup {\n"
"    background-color: #f973ab;\n"
"    color: #ffffff;\n"
"    border-radius: 16px;\n"
"    padding: 6px 18px;\n"
"    font-weight: 600;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#pushButton_signup:hover {\n"
"    background-color: #"
                        "fb7185;\n"
"}\n"
"\n"
"QPushButton#pushButton_signup:pressed {\n"
"    background-color: #f43f5e;\n"
"}\n"
"\n"
"QPushButton {\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"}\n"
"   "));
        verticalLayout = new QVBoxLayout(signuppage);
        verticalLayout->setObjectName("verticalLayout");
        label_title = new QLabel(signuppage);
        label_title->setObjectName("label_title");
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_title);

        label_info = new QLabel(signuppage);
        label_info->setObjectName("label_info");
        QFont font1;
        font1.setBold(true);
        label_info->setFont(font1);
        label_info->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_info);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_2 = new QLabel(signuppage);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        label_2->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit_username = new QLineEdit(signuppage);
        lineEdit_username->setObjectName("lineEdit_username");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_username);

        label_3 = new QLabel(signuppage);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_password = new QLineEdit(signuppage);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_password);


        verticalLayout->addLayout(formLayout);

        label_note = new QLabel(signuppage);
        label_note->setObjectName("label_note");
        QFont font3;
        font3.setPointSize(9);
        label_note->setFont(font3);
        label_note->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_note->setWordWrap(true);

        verticalLayout->addWidget(label_note);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        pushButton_signup = new QPushButton(signuppage);
        pushButton_signup->setObjectName("pushButton_signup");

        buttonLayout->addWidget(pushButton_signup);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(signuppage);

        QMetaObject::connectSlotsByName(signuppage);
    } // setupUi

    void retranslateUi(QDialog *signuppage)
    {
        signuppage->setWindowTitle(QCoreApplication::translate("signuppage", "Create Account", nullptr));
        label_title->setText(QCoreApplication::translate("signuppage", "Create your account", nullptr));
        label_info->setText(QCoreApplication::translate("signuppage", "Please choose a username and password:", nullptr));
        label_2->setText(QCoreApplication::translate("signuppage", "Username:", nullptr));
        label_3->setText(QCoreApplication::translate("signuppage", "Password:", nullptr));
        label_note->setText(QCoreApplication::translate("signuppage", "Note: If signup is successful, this window will close automatically.", nullptr));
        pushButton_signup->setText(QCoreApplication::translate("signuppage", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signuppage: public Ui_signuppage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPPAGE_H
