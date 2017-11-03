#ifndef REGISTERUI_H
#define REGISTERUI_H

#include <QWidget>
#include <Qstring>

namespace Ui {
class registerUI;
}

class registerUI : public QWidget
{
    Q_OBJECT

public:
    explicit registerUI(QWidget *parent = 0);
    ~registerUI();

private slots:
	void on_quit_clicked();

	void on_register_2_clicked();

	void receive_show_register();

private:
    Ui::registerUI *register_ui;
	void closeEvent(QCloseEvent *Event);

signals:
	void quit_register();

};

#endif // REGISTERUI_H
