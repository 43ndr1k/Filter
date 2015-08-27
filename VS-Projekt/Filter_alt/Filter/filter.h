#ifndef FILTER_H
#define FILTER_H

#include <QtWidgets/QMainWindow>
#include "ui_filter.h"

class Filter : public QMainWindow
{
	Q_OBJECT

public:
	Filter(QWidget *parent = 0);
	~Filter();

private:
	Ui::FilterClass ui;

	public slots:
	void openPic();

};

#endif // FILTER_H
