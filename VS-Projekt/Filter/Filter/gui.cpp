#include "gui.h"
#include "data.h"
#include <QFileDialog>

GUI::GUI(QWidget *parent)
: QMainWindow(parent)
{
	//_CrtSetDbgFlag(_CrtSetDbgFlag(0) | _CRTDBG_CHECK_ALWAYS_DF);
	ui.setupUi(this);
}

GUI::~GUI()
{

}

void GUI::loadPic(){
	myData.readPic(QFileDialog::getOpenFileName(this, tr("Bild laden"), "" ,tr("Bilder (*.ppm)")));

	ui.picture->setPixmap(QPixmap::fromImage(this->myData.getImage()));
}

void GUI::savePic(){
	myData.savePic(QFileDialog::getSaveFileName(this, tr("Bild speichern"), myData.getPic().getPath() ,tr("Bilder (*.ppm)")));
}