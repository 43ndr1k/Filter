#include "gui.h"
#include <QFileDialog>

GUI::GUI(QWidget *parent)
: QMainWindow(parent)
{
	//_CrtSetDbgFlag(_CrtSetDbgFlag(0) | _CRTDBG_CHECK_ALWAYS_DF);
	ui.setupUi(this);
	myData = &Data::getInstance();
	opt = &Options::getInstance();
}

GUI::~GUI()
{

}

void GUI::loadPic(){
	myData->readPic(QFileDialog::getOpenFileName(this, tr("Bild laden"), "" ,tr("Bilder (*.ppm)")));

	ui.picture->setPixmap(QPixmap::fromImage(myData->getImage()));
}

void GUI::savePic(){
	myData->savePic(QFileDialog::getSaveFileName(this, tr("Bild speichern"), myData->getPic().getPath() ,tr("Bilder (*.ppm)")));
}

void GUI::back(){
	myData->setPic(myData->getLastPic());
	ui.picture->setPixmap(QPixmap::fromImage(myData->getImage()));
}

void GUI::makeGray(){
	opt->makeGray();
	ui.picture->setPixmap(QPixmap::fromImage(myData->getImage()));
}

void GUI::threshold(){
	opt->threshold();
	ui.picture->setPixmap(QPixmap::fromImage(myData->getImage()));
}

void GUI::meanValue(){
	opt->meanValue();
	ui.picture->setPixmap(QPixmap::fromImage(myData->getImage()));
}

void GUI::gauss(){
	opt->gauss();
	ui.picture->setPixmap(QPixmap::fromImage(myData->getImage()));
}

void GUI::hSobel(){
	opt->hSobel();
	ui.picture->setPixmap(QPixmap::fromImage(myData->getImage()));
}

void GUI::vSobel(){
	opt->vSobel();
	ui.picture->setPixmap(QPixmap::fromImage(myData->getImage()));
}

void GUI::qSobel(){
	opt->qSobel();
	ui.picture->setPixmap(QPixmap::fromImage(myData->getImage()));
}

void GUI::kSobel(){
	opt->kSobel();
	ui.picture->setPixmap(QPixmap::fromImage(myData->getImage()));
}

void GUI::thresholdSobel(){
	opt->thresholdSobel();
	ui.picture->setPixmap(QPixmap::fromImage(myData->getImage()));
}