#include "mainwindow.h"
#include "registerui.h"
#include "userui.h"
#include "AgendaService.hpp"
#include <QApplication>
#include <QString>
#include <QDatetime>
#include <QTimer>
#include <QLabel>
#include <string>
using std::string;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    registerUI r;
	userUI u;
	extern AgendaService agenda;
    w.show();

    QObject::connect(&w, SIGNAL(show_register()), &r, SLOT(receive_show_register()));
	QObject::connect(&w, SIGNAL(show_user(string)), &u, SLOT(receive_show_user(string)));
	QObject::connect(&r, SIGNAL(quit_register()), &w, SLOT(receive_show_login()));
	QObject::connect(&u, SIGNAL(quit_user()), &w, SLOT(receive_show_login()));
	QObject::connect(&u, SIGNAL(user_show_login()), &w, SLOT(receive_show_login()));
    return a.exec();
}
