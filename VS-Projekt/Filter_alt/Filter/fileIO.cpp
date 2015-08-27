#include "fileIO.h"
#include <QFileDialog>
#include "msgBox.h"

QString FileIO::openFile(){
	QString fname;
	fname = QFileDialog::getOpenFileName();
	if (fname == nullptr){
		msgBox msg("Keine g�ltige Datei!", "Neue Datei versuchen?");
		msg.exec();
	}
	return fname;
}