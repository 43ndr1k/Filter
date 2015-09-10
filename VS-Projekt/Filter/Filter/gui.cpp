#include "gui.h"
#include "data.h"
#include <QFileDialog>

GUI::GUI(QWidget *parent)
: QMainWindow(parent)
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(0) | _CRTDBG_CHECK_ALWAYS_DF);
	ui.setupUi(this);
}

GUI::~GUI()
{

}

void GUI::loadPic(){
	this->myData.readPic(QFileDialog::getOpenFileName());

	ui.picture->setPixmap(QPixmap::fromImage(this->myData.getImage()));

	//ui.picture->setPixmap(QPixmap(QFileDialog::getOpenFileName()));
}