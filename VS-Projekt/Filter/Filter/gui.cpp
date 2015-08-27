#include "gui.h"
#include <QFileDialog>

GUI::GUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

GUI::~GUI()
{

}

void GUI::loadPic(){
	ui.picture->setPixmap(QPixmap(QFileDialog::getOpenFileName()));
}
