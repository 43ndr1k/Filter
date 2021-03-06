#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QMainWindow>
#include "ui_gui.h"
#include "data.h"
#include "options.h"

class GUI : public QMainWindow
{
	Q_OBJECT

public:
	GUI(QWidget *parent = 0);
	~GUI();

private:
	Ui::GUIClass ui;
	Data* myData;
	Options* opt;

	public slots:
	void loadPic();
	void savePic();
	void back();
	void makeGray();
	void threshold();
	void meanValue();
	void gauss();
	void hSobel();
	void vSobel();
	void qSobel();
	void kSobel();
	void thresholdSobel();
};

#endif // GUI_H
