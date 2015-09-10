#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QMainWindow>
#include "ui_gui.h"
#include "data.h"

class GUI : public QMainWindow
{
	Q_OBJECT

public:
	GUI(QWidget *parent = 0);
	~GUI();

private:
	Ui::GUIClass ui;
	Data myData;

	public slots:
	void loadPic();
};

#endif // GUI_H
