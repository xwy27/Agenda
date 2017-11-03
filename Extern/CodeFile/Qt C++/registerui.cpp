#include "registerui.h"
#include "ui_registerui.h"
#include "AgendaService.hpp"
#include <string>
#include <Qstring>
#include <QCloseEvent>
#include <Qmessagebox>
using std::string;

AgendaService temp_2;

QString str3qstr(const string str) {
	return QString::fromLocal8Bit(str.data());
}

string qstr3str(const QString qstr) {
	QByteArray cdata = qstr.toLocal8Bit();
	return string(cdata);
}

registerUI::registerUI(QWidget *parent) :
    QWidget(parent),
	register_ui(new Ui::registerUI) {
	register_ui->setupUi(this);
	register_ui->username->setPlaceholderText("username...");
	register_ui->password->setPlaceholderText("password...");
	register_ui->email->setPlaceholderText("email...");
	register_ui->phone->setPlaceholderText("phone...");
	this->setWindowTitle("Agenda");
}

registerUI::~registerUI() {
    delete register_ui;
}

void registerUI::closeEvent(QCloseEvent *Event) {
	int flag = QMessageBox::question(this, "Quit", "Sure To Quit?", QMessageBox::Yes, QMessageBox::No);
	if (flag != 16384) {
		Event->ignore();
	} else {
		temp_2.quitAgenda();
		Event->accept();
	}
}

void registerUI::on_register_2_clicked() {
	string username, password, email, phone;
	username = qstr3str(this->register_ui->username->text());
	password = qstr3str(register_ui->password->text());
	email = qstr3str(register_ui->email->text());
	phone = qstr3str(register_ui->phone->text());
	if (username.size() > 5 && username.size() < 21 &&
		password.size() > 8 && password.size() < 21 &&
		temp_2.userRegister(username, password, email, phone)) {
		QMessageBox::information(this, "Accepted", "Register successfully");
	} else {
		QMessageBox::warning(this, "Error", "Pay attention to the request for username and password!");
	}
}

void registerUI::on_quit_clicked() {
	emit quit_register();
	this->hide();
}

void registerUI::receive_show_register() {
	this->show();
	this->activateWindow();
}