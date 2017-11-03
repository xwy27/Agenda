#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <string>
#include <Qmessagebox>
#include <Qstring>
#include <QCloseEvent>
#include "AgendaService.hpp"
using std::string;

AgendaService temp;

QString str2qstr(const string str) {
	return QString::fromLocal8Bit(str.data());
}

string qstr2str(const QString qstr) {
	QByteArray cdata = qstr.toLocal8Bit();
	return string(cdata);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
	ui->lineEdit->setPlaceholderText("Your username...");
	ui->lineEdit_2->setPlaceholderText("Your password...");
    //set mainWindow title
    this->setWindowTitle("Agenda");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event) {
	int flag = QMessageBox::question(this, "Quit", "Sure To Quit?", QMessageBox::Yes, QMessageBox::No);
	if (flag != 16384) {
		event->ignore();
	} else {
		temp.quitAgenda();
		event->accept();
	}
}

void MainWindow::on_login_clicked() {
	string username, password;
	username = qstr2str(this->ui->lineEdit->text());
	password = qstr2str(this->ui->lineEdit_2->text());
	if (temp.userLogIn(username, password)) {
		this->hide();
		this->ui->lineEdit->clear();
		this->ui->lineEdit_2->clear();
		emit show_user(username);
	} else {
		QMessageBox::warning(this, "Error", "User doesn't existed  or incorrect password!");
	}
}

void MainWindow::on_register_2_clicked() {
    this->hide();
	emit show_register();
}

void MainWindow::on_pushButton_3_clicked() {
    this->close();
}

void MainWindow::receive_show_login() {
	this->show();
	this->activateWindow();
}
