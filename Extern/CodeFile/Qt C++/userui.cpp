#include "userui.h"
#include "ui_userui.h"
#include <QMessagebox> 
#include <string>
#include <Qstring>
#include <QDatetime>
#include <QTimer>
#include <QLabel>
#include <list>
#include <vector>
#include <sstream>
#include "AgendaService.hpp"
using std::string;
using std::list;

AgendaService temp_user;

//string To Qstring
QString str4qstr(const string str) {
	return QString::fromLocal8Bit(str.data());
}

//Qstring to string
string qstr4str(const QString qstr) {
	QByteArray cdata = qstr.toLocal8Bit();
	return string(cdata);
}

userUI::userUI(QWidget *parent) :
    QWidget(parent),
    user_ui(new Ui::userUI) {
    
	user_ui->setupUi(this);
	this->setWindowTitle("Agenda");//设置窗口标题
	myStack = user_ui->stackedWidget;
	myList = user_ui->listWidget;
	user_table_refresh();//刷新user窗口数据

	//所有输入框设置输入提示
	user_ui->title_search->setPlaceholderText("Title");
	user_ui->stime_search->setPlaceholderText("yyyy-mm-dd/hh:mm");
	user_ui->etime_search->setPlaceholderText("yyyy-mm-dd/hh:mm");
	user_ui->new_stime->setPlaceholderText("yyyy-mm-dd/hh:mm");
	user_ui->new_etime->setPlaceholderText("yyyy-mm-dd/hh:mm");
	user_ui->new_part->setPlaceholderText("a&b&c&...");
	user_ui->new_title->setPlaceholderText("Title");
	user_ui->add_title->setPlaceholderText("Title");
	user_ui->add_part->setPlaceholderText("One name for one time...");
	user_ui->remove_title_2->setPlaceholderText("Title");
	user_ui->remove_part_2->setPlaceholderText("One name for one time");
	user_ui->quit_title->setPlaceholderText("Title");
	user_ui->lineEdit->setPlaceholderText("Title");
	user_ui->password->setPlaceholderText("Your password...");
	user_ui->new_email->setPlaceholderText("No format check...");
	user_ui->new_phone->setPlaceholderText("No format check...");
	user_ui->old_password->setPlaceholderText("Your current password...");
	user_ui->new_password->setPlaceholderText("The length of new password should be 9 to 20.");
	
	myStack->setCurrentIndex(0);//设置初始页面
	//设置数据显示界面无法编辑
	this->user_ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->user_ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->user_ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->user_ui->tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->user_ui->tableWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);
	connect(myList, SIGNAL(currentRowChanged(int)), myStack, SLOT(setCurrentIndex(int)));//连接左侧列表界面和右侧显示界面

	QTimer *timer = new QTimer(this);
	timer->start(1000); // 每次发射timeout信号时间间隔为1秒
	connect(timer, SIGNAL(timeout()), this, SLOT(timeUpdate()));//发射时间信号
	connect(timer, SIGNAL(timeout()), this, SLOT(matchedTime()));//发射到时间会议信号
}

void userUI::matchedTime() {
	QDateTime CurrentTime = QDateTime::currentDateTime();//获取当前时间
	QString Timestr = CurrentTime.toString("yyyy-MM-dd/hh:mm"); // 设置显示的格式
	string curTime = qstr4str(Timestr);
	bool flag = 0;
	list<Meeting> temp = temp_user.listAllMeetings(username);
	for (auto i : temp) {
		if (i.getStartDate() == curTime) {
			flag = 1;
			string message;
			message = message + "It's time for meeting : '" + i.getTitle() + "'";
			user_ui->label_36->setText(str4qstr(message));
		}
	}
	if (!flag) {
		user_ui->label_36->clear();//会议时间未到则清空提醒
	}
}

void userUI::timeUpdate() {
	QDateTime CurrentTime = QDateTime::currentDateTime();
	QString Timestr = CurrentTime.toString("yyyy-MM-dd/hh:mm:ss"); // 设置显示的格式
	user_ui->timeLabel->setText(Timestr);
}

userUI::~userUI() {
    delete user_ui;
}

void userUI::closeEvent(QCloseEvent *event) {
	//经过测试，窗口关闭Yes按钮的返回值是int类型，值为16384
	int flag = QMessageBox::question(this, "Quit", "Sure To Quit?", QMessageBox::Yes, QMessageBox::No);
	if (flag != 16384) {
		event->ignore();
	} else {
		temp_user.quitAgenda();
		event->accept();
	}
}

void userUI::user_table_refresh() {
	list<User> user = temp_user.listAllUsers();
	int row = 0;
	user_ui->tableWidget->setRowCount(0);
	for (auto i : user) {
		user_ui->tableWidget->insertRow(row);
		string uname = i.getName();
		string umail = i.getEmail();
		string uphone = i.getPhone();
		user_ui->tableWidget->setItem(row, 0, new QTableWidgetItem(str4qstr(uname)));
		user_ui->tableWidget->setItem(row, 1, new QTableWidgetItem(str4qstr(umail)));
		user_ui->tableWidget->setItem(row, 2, new QTableWidgetItem(str4qstr(uphone)));
		row++;
	}
	list<User> temp = temp_user.listAllUsers();
	int row2 = 0;
	user_ui->tableWidget_6->setRowCount(0);
	for (auto i : temp) {
		if (i.getName() == username) {
			user_ui->tableWidget_6->insertRow(row2);
			string uname = i.getName();
			string umail = i.getEmail();
			string uphone = i.getPhone();
			user_ui->tableWidget_6->setItem(row2, 0, new QTableWidgetItem(str4qstr(uname)));
			user_ui->tableWidget_6->setItem(row2, 1, new QTableWidgetItem(str4qstr(umail)));
			user_ui->tableWidget_6->setItem(row2, 2, new QTableWidgetItem(str4qstr(uphone)));
			row2++;
		}
	}
}

void userUI::meeting_table_refresh() {
	user_ui->tableWidget_5->setRowCount(0);
	list<Meeting> all, sponsored, part;
	all = temp_user.listAllMeetings(username);
	sponsored = temp_user.listAllSponsorMeetings(username);
	part = temp_user.listAllParticipateMeetings(username);

	int row = 0;
	string title, sponsor, stime, etime, participator;
	if (all.empty()) {
		row = 0;
		user_ui->tableWidget_2->setRowCount(0);
		user_ui->tableWidget_2->insertRow(row);
		user_ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(str4qstr("No Meeting is Matched")));
	} else {
		row = 0;
		user_ui->tableWidget_2->setRowCount(0);
		for (auto i : all) {
			title = i.getTitle();
			sponsor = i.getSponsor();
			stime = i.getStartDate().dateToString(i.getStartDate());
			etime = i.getEndDate().dateToString(i.getEndDate());
			participator = "";
			for (int k = 0; k < i.getParticipator().size(); ++k) {
				participator += i.getParticipator()[k];
				if (k != i.getParticipator().size() - 1) {
					participator += ",";
				}
			}
			user_ui->tableWidget_2->insertRow(row);
			user_ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(str4qstr(title)));
			user_ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(str4qstr(sponsor)));
			user_ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(str4qstr(stime)));
			user_ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(str4qstr(etime)));
			user_ui->tableWidget_2->setItem(row, 4, new QTableWidgetItem(str4qstr(participator)));
			row++;
		}
	}
	
	if (sponsored.empty()) {
		row = 0;
		user_ui->tableWidget_3->setRowCount(0);
		user_ui->tableWidget_3->insertRow(row);
		user_ui->tableWidget_3->setItem(row, 0, new QTableWidgetItem(str4qstr("No Meeting is Matched")));
	} else {
		row = 0;
		user_ui->tableWidget_3->setRowCount(0);
		for (auto i : sponsored) {
			title = i.getTitle();
			sponsor = i.getSponsor();
			stime = i.getStartDate().dateToString(i.getStartDate());
			etime = i.getEndDate().dateToString(i.getEndDate());
			participator = "";
			for (int k = 0; k < i.getParticipator().size(); ++k) {
				participator += i.getParticipator()[k];
				if (k != i.getParticipator().size() - 1) {
					participator += ",";
				}
			}
			user_ui->tableWidget_3->insertRow(row);
			user_ui->tableWidget_3->setItem(row, 0, new QTableWidgetItem(str4qstr(title)));
			user_ui->tableWidget_3->setItem(row, 1, new QTableWidgetItem(str4qstr(sponsor)));
			user_ui->tableWidget_3->setItem(row, 2, new QTableWidgetItem(str4qstr(stime)));
			user_ui->tableWidget_3->setItem(row, 3, new QTableWidgetItem(str4qstr(etime)));
			user_ui->tableWidget_3->setItem(row, 4, new QTableWidgetItem(str4qstr(participator)));
			row++;
		}
	}
	
	if (part.empty()) {
		row = 0;
		user_ui->tableWidget_4->setRowCount(0);
		user_ui->tableWidget_4->insertRow(row);
		user_ui->tableWidget_4->setItem(row, 0, new QTableWidgetItem(str4qstr("No Meeting is Matched")));
	} else {
		row = 0;
		user_ui->tableWidget_4->setRowCount(0);
		for (auto i : part) {
			title = i.getTitle();
			sponsor = i.getSponsor();
			stime = i.getStartDate().dateToString(i.getStartDate());
			etime = i.getEndDate().dateToString(i.getEndDate());
			participator = "";
			for (int k = 0; k < i.getParticipator().size(); ++k) {
				participator += i.getParticipator()[k];
				if (k != i.getParticipator().size() - 1) {
					participator += ",";
				}
			}
			user_ui->tableWidget_4->insertRow(row);
			user_ui->tableWidget_4->setItem(row, 0, new QTableWidgetItem(str4qstr(title)));
			user_ui->tableWidget_4->setItem(row, 1, new QTableWidgetItem(str4qstr(sponsor)));
			user_ui->tableWidget_4->setItem(row, 2, new QTableWidgetItem(str4qstr(stime)));
			user_ui->tableWidget_4->setItem(row, 3, new QTableWidgetItem(str4qstr(etime)));
			user_ui->tableWidget_4->setItem(row, 4, new QTableWidgetItem(str4qstr(participator)));
			row++;
		}
	}
}

void userUI::on_t_search_clicked() {
	string temp;
	temp = qstr4str(this->user_ui->title_search->text());
	list<Meeting> meeting = temp_user.meetingQuery(username, temp);

	if (meeting.empty()) {
		QMessageBox::warning(this, "Error", "No meeting is matched!");
	} else {
		//show info of matched meeting
		string title = meeting.front().getTitle();
		string sponsor = meeting.front().getSponsor();
		string stime = meeting.front().getStartDate().dateToString(meeting.front().getStartDate());
		string etime = meeting.front().getEndDate().dateToString(meeting.front().getEndDate());
		string participator;

		for (int i = 0; i < meeting.front().getParticipator().size(); ++i)  {
			participator += meeting.front().getParticipator()[i];
			if (i != meeting.front().getParticipator().size() - 1) {
				participator += ",";
			}
		}
		user_ui->tableWidget_5->setRowCount(0);
		user_ui->tableWidget_5->insertRow(0);
		user_ui->tableWidget_5->setItem(0, 0, new QTableWidgetItem(str4qstr(title)));
		user_ui->tableWidget_5->setItem(0, 1, new QTableWidgetItem(str4qstr(sponsor)));
		user_ui->tableWidget_5->setItem(0, 2, new QTableWidgetItem(str4qstr(stime)));
		user_ui->tableWidget_5->setItem(0, 3, new QTableWidgetItem(str4qstr(etime)));
		user_ui->tableWidget_5->setItem(0, 4, new QTableWidgetItem(str4qstr(participator)));
	}
	this->user_ui->title_search->clear();
}

void userUI::on_time_search_clicked() {
	string stime, etime;
	stime = qstr4str(this->user_ui->stime_search->text());
	etime = qstr4str(this->user_ui->etime_search->text());
	list<Meeting> meeting = temp_user.meetingQuery(username, stime, etime);
	if (meeting.empty()) {
		QMessageBox::warning(this, "Error", "No meeting is matched!");
	}
	else {
		//show info of matched meeting
		int row = 0;
		for (auto i : meeting) {
			string title = i.getTitle();
			string sponsor = i.getSponsor();
			string stime = i.getStartDate().dateToString(i.getStartDate());
			string etime = i.getEndDate().dateToString(i.getEndDate());
			string participator;

			for (int j = 0; j < i.getParticipator().size(); ++j) {
				participator += i.getParticipator()[j];
				if (j != i.getParticipator().size() - 1) {
					participator += ",";
				}
			}
			user_ui->tableWidget_5->setRowCount(row);
			user_ui->tableWidget_5->insertRow(row);
			user_ui->tableWidget_5->setItem(row, 0, new QTableWidgetItem(str4qstr(title)));
			user_ui->tableWidget_5->setItem(row, 1, new QTableWidgetItem(str4qstr(sponsor)));
			user_ui->tableWidget_5->setItem(row, 2, new QTableWidgetItem(str4qstr(stime)));
			user_ui->tableWidget_5->setItem(row, 3, new QTableWidgetItem(str4qstr(etime)));
			user_ui->tableWidget_5->setItem(row, 4, new QTableWidgetItem(str4qstr(participator)));
			row++;
		}
	}
	this->user_ui->stime_search->clear();
	this->user_ui->etime_search->clear();
}

void userUI::on_create_clicked(){
	string title, stime, etime, part; 
	std::vector<string> true_part;
	title = qstr4str(this->user_ui->new_title->text());
	stime = qstr4str(this->user_ui->new_stime->text());
	etime = qstr4str(this->user_ui->new_etime->text());
	part = qstr4str(this->user_ui->new_part->text());
	if (title.size() == 0 || stime.size() == 0 || etime.size() == 0 || part.size() == 0) {
		QMessageBox::warning(this, "Error", "Pay attention to the information you provide!");
	} else {
		std::stringstream name;
		name << part;
		string str;
		while (std::getline(name, str, '&')) {
			true_part.push_back(str);
		}
		if (temp_user.createMeeting(username, title, stime, etime, true_part)) {
			QMessageBox::information(this, "Accepted", "Meeting is created!");
		} else {
			QMessageBox::warning(this, "Error", "Pay attention to the information you provide!");
		}
	}
	this->user_ui->new_title->clear();
	this->user_ui->new_stime->clear();
	this->user_ui->new_etime->clear();
	this->user_ui->new_part->clear();
	meeting_table_refresh();
}

void userUI::on_add_clicked(){
	string title, part;
	title = qstr4str(this->user_ui->add_title->text());
	part = qstr4str(this->user_ui->add_part->text());
	if (temp_user.addMeetingParticipator(username, title, part)) {
		QMessageBox::information(this, "Accepted", "Participator is added!");
	} else {
		QMessageBox::warning(this, "Error", "Pay attention to the information you provide!");
	}
	this->user_ui->add_part->clear();
	this->user_ui->add_title->clear();
	meeting_table_refresh();
}

void userUI::on_remove_clicked(){
	string title, part;
	title = qstr4str(this->user_ui->remove_title_2->text());
	part = qstr4str(this->user_ui->remove_part_2->text());
	if (temp_user.removeMeetingParticipator(username, title, part)) {
		QMessageBox::information(this, "Accepted", "Participator is removed!");
	}
	else {
		QMessageBox::warning(this, "Error", "Pay attention to the information you provide!");
	}
	this->user_ui->remove_part_2->clear();
	this->user_ui->remove_title_2->clear();
	meeting_table_refresh();
}

void userUI::on_quitMeeting_clicked() {
	string title;
	title = qstr4str(this->user_ui->quit_title->text());
	if (temp_user.quitMeeting(username, title)) {
		QMessageBox::information(this, "Accepted", "Meeting is quitted!");
	} else {
		QMessageBox::warning(this, "Error", "Pay attention to the information you provide!");
	}
	this->user_ui->quit_title->clear();
	meeting_table_refresh();
}

void userUI::on_delete_title_clicked() {
	string title;
	title = qstr4str(this->user_ui->lineEdit->text());
	if (temp_user.deleteMeeting(username, title)) {
		QMessageBox::information(this, "Accepted", "Meeting is deleted!");
	} else {
		QMessageBox::warning(this, "Error", "Pay attention to the information you provide!");
	}
	this->user_ui->lineEdit->clear();
	meeting_table_refresh();
}

void userUI::on_delete_all_clicked() {
	if (temp_user.deleteAllMeetings(username)) {
		QMessageBox::information(this, "Accepted", " All Meeting is deleted!");
	} else {
		QMessageBox::warning(this, "Error", "Wrong Operation!");
	}
	meeting_table_refresh();
}

void userUI::on_resetInfo_clicked() {
	string email, phone;
	email = qstr4str(this->user_ui->new_email->text());
	phone = qstr4str(this->user_ui->new_phone->text());
	if (temp_user.resetInfo(username, email, phone)) {
		user_table_refresh();
		QMessageBox::information(this, "Accepted", "Information is resetted!");
	} else {
		QMessageBox::warning(this, "Error", "Empty Email and Phone is invalid!");
	}
	this->user_ui->new_email->clear();
	this->user_ui->new_phone->clear();
}

void userUI::on_resetPsd_clicked() {
	string old_psd, new_psd;
	old_psd = qstr4str(this->user_ui->old_password->text());
	new_psd = qstr4str(this->user_ui->new_password->text());
	int flag = temp_user.resetPsd(username, old_psd, new_psd);
	if (flag == 1) {
		QMessageBox::information(this, "Accepted", "Password is resetted!");
	} else if (flag == 2) {
		QMessageBox::warning(this, "Error", "Old password is wrong!");
	} else {
		QMessageBox::warning(this, "Error", "Pay attention to the length of new password!");
	}
	this->user_ui->old_password->clear();
	this->user_ui->new_password->clear();
}

void userUI::on_delete_me_clicked() {
	string psd;
	psd = qstr4str(this->user_ui->password->text());
	if (temp_user.deleteUser(username, psd)) {
		QMessageBox::information(this, "Accepted", "Account is deleted!");
	} else {
		QMessageBox::warning(this, "Error", "Wrong Password!");
	}
	this->user_ui->password->clear();
	this->hide();
	emit user_show_login();
}

void userUI::on_quit_clicked() {
	this->hide();
	emit quit_user();
}

void userUI::receive_show_user(string user) {
	this->username = user;
	string greeting = "Hello, " + username;
	this->user_ui->space->setText(str4qstr(greeting));
	user_table_refresh();
	meeting_table_refresh();
	this->user_ui->stackedWidget->setCurrentIndex(0);
	this->show();
	this->activateWindow();
}
