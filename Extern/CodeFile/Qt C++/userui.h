#ifndef USERUI_H
#define USERUI_H

#include <QWidget>
#include <QStackedwidget>
#include <QListwidget>
#include <QCloseEvent>
#include <string>
using std::string;

namespace Ui {
class userUI;
}

class userUI : public QWidget {
    Q_OBJECT

public:
    explicit userUI(QWidget *parent = 0);
    ~userUI();

private slots:
	void on_quit_clicked();
	void on_t_search_clicked();
	void on_time_search_clicked();
	void on_create_clicked();
	void on_add_clicked();
	void on_remove_clicked();
	void on_quitMeeting_clicked();
	void on_delete_me_clicked();
	void on_delete_all_clicked();
	void on_resetInfo_clicked();
	void on_resetPsd_clicked();
	void on_delete_title_clicked();
	void receive_show_user(string user);
	void timeUpdate();
	void matchedTime();

private:
    Ui::userUI *user_ui;
	QStackedWidget *myStack;
	QListWidget *myList;
	string username;
	void closeEvent(QCloseEvent *event);
	void user_table_refresh();
	void meeting_table_refresh();
signals:
	void quit_user();
	void user_show_login();
};

#endif // USERUI_H
