/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *layout;
    QPushButton *login;
    QPushButton *register_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 304);
        layout = new QWidget(MainWindow);
        layout->setObjectName(QStringLiteral("layout"));
        login = new QPushButton(layout);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(30, 160, 93, 28));
        login->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        register_2 = new QPushButton(layout);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(150, 160, 93, 28));
        register_2->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        pushButton_3 = new QPushButton(layout);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(270, 160, 93, 28));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        label = new QLabel(layout);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 0, 271, 61));
        label->setStyleSheet(QStringLiteral("font: 87 25pt \"Arial Black\";"));
        label_2 = new QLabel(layout);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 70, 72, 15));
        label_3 = new QLabel(layout);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 100, 72, 15));
        lineEdit = new QLineEdit(layout);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 70, 171, 21));
        lineEdit_2 = new QLineEdit(layout);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(160, 100, 171, 21));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(layout);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 250, 171, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 25 italic 9pt \"\347\255\211\347\272\277 Light\";"));
        label_5 = new QLabel(layout);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(300, 30, 31, 16));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277 Light\";"));
        MainWindow->setCentralWidget(layout);
        login->raise();
        register_2->raise();
        label->raise();
        pushButton_3->raise();
        label_2->raise();
        label_3->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        label_4->raise();
        label_5->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        login->setText(QApplication::translate("MainWindow", "login", 0));
        register_2->setText(QApplication::translate("MainWindow", "register", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "quit", 0));
        label->setText(QApplication::translate("MainWindow", "      Agenda", 0));
        label_2->setText(QApplication::translate("MainWindow", "username", 0));
        label_3->setText(QApplication::translate("MainWindow", "password", 0));
        label_4->setText(QApplication::translate("MainWindow", "Copyright (c) 2017 Agenda", 0));
        label_5->setText(QApplication::translate("MainWindow", "V1.0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
