/********************************************************************************
** Form generated from reading UI file 'registerui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERUI_H
#define UI_REGISTERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerUI
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *username;
    QLineEdit *email;
    QLineEdit *password;
    QLineEdit *phone;
    QPushButton *register_2;
    QPushButton *quit;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;

    void setupUi(QWidget *registerUI)
    {
        if (registerUI->objectName().isEmpty())
            registerUI->setObjectName(QStringLiteral("registerUI"));
        registerUI->resize(539, 423);
        label = new QLabel(registerUI);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 30, 361, 81));
        label->setStyleSheet(QStringLiteral("font: 87 25pt \"Arial Black\";"));
        label_2 = new QLabel(registerUI);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 120, 72, 15));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        label_3 = new QLabel(registerUI);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 180, 72, 15));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        label_4 = new QLabel(registerUI);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 230, 72, 15));
        label_4->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        label_5 = new QLabel(registerUI);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 280, 72, 15));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        username = new QLineEdit(registerUI);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(190, 120, 261, 21));
        email = new QLineEdit(registerUI);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(190, 230, 261, 21));
        password = new QLineEdit(registerUI);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(190, 180, 261, 21));
        password->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        phone = new QLineEdit(registerUI);
        phone->setObjectName(QStringLiteral("phone"));
        phone->setGeometry(QRect(190, 280, 261, 21));
        register_2 = new QPushButton(registerUI);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(160, 340, 93, 28));
        register_2->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        quit = new QPushButton(registerUI);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setGeometry(QRect(330, 340, 93, 28));
        quit->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        label_6 = new QLabel(registerUI);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(190, 150, 321, 16));
        label_6->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        label_7 = new QLabel(registerUI);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 210, 261, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        label_8 = new QLabel(registerUI);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(190, 260, 131, 16));
        label_8->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        label_9 = new QLabel(registerUI);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 310, 121, 16));
        label_9->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        label_10 = new QLabel(registerUI);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(360, 400, 171, 20));
        label_10->setStyleSheet(QString::fromUtf8("font: 25 italic 9pt \"\347\255\211\347\272\277 Light\";"));
        label_11 = new QLabel(registerUI);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(370, 70, 31, 16));
        label_11->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));

        retranslateUi(registerUI);

        QMetaObject::connectSlotsByName(registerUI);
    } // setupUi

    void retranslateUi(QWidget *registerUI)
    {
        registerUI->setWindowTitle(QApplication::translate("registerUI", "Form", 0));
        label->setText(QApplication::translate("registerUI", "       Agenda", 0));
        label_2->setText(QApplication::translate("registerUI", "username", 0));
        label_3->setText(QApplication::translate("registerUI", "password", 0));
        label_4->setText(QApplication::translate("registerUI", "email", 0));
        label_5->setText(QApplication::translate("registerUI", "phone", 0));
        register_2->setText(QApplication::translate("registerUI", "register", 0));
        quit->setText(QApplication::translate("registerUI", "quit", 0));
        label_6->setText(QApplication::translate("registerUI", "The length of usrname should be 6 to 20 ", 0));
        label_7->setText(QApplication::translate("registerUI", "The length of password should be 9 to 20 ", 0));
        label_8->setText(QApplication::translate("registerUI", "No format check", 0));
        label_9->setText(QApplication::translate("registerUI", "No format check", 0));
        label_10->setText(QApplication::translate("registerUI", "Copyright (c) 2017 Agenda", 0));
        label_11->setText(QApplication::translate("registerUI", "V1.0", 0));
    } // retranslateUi

};

namespace Ui {
    class registerUI: public Ui_registerUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERUI_H
