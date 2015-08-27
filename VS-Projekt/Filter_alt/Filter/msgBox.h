#ifndef MSGBOX_H
#define MSGBOX_H

#include <QMessageBox>

class msgBox : public QMessageBox
{

public:
	msgBox(char mainmessage[], char info[]);

private:

};

#endif // MSGBOX_H