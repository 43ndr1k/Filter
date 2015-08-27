#include "filter.h"
#include <cstdlib>
#include <QFileDialog>
#include "msgBox.h"

Filter::Filter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Filter::~Filter()
{

}

void Filter::openPic(){
	QString fname;
	fname = QFileDialog::getOpenFileName();

	QPixmap image(fname);
	bool picNewLoad = image.isNull();
	//while (picNewLoad){
		msgBox msg("Kein gültiges Bild!", "Neues Bild versuchen?");
		int button = msg.exec();
		switch (button) {
			//case QMessageBox::Save
		}
	//}
	ui.picture->setPixmap(image);
}