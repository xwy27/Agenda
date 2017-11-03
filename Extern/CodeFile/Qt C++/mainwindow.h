#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <string>
#include <Qstring>
using std::string;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
	void on_login_clicked();

    void on_register_2_clicked();

    void on_pushButton_3_clicked();

	void receive_show_login();

private:
    Ui::MainWindow *ui;
	void closeEvent(QCloseEvent *event);

signals:
	void show_register();

	void show_user(string);
};

#endif // MAINWINDOW_H
