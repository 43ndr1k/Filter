#include "msgBox.h"
#include <QString>

msgBox::msgBox(char mainmessage[], char info[])
{
	this->setText(QString::fromLatin1(mainmessage));
	this->setInformativeText(QString::fromLatin1(info));
	this->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	this->setDefaultButton(QMessageBox::Yes);
}
