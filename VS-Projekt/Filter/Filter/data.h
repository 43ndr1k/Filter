#ifndef DATA_H
#define DATA_H

#include "picture.h"

class Data
{

public:
	static Data& getInstance();

	Picture getPic();
	Picture getLastPic();
	QImage getImage();

	void setPic(Picture pic);
	void readPic(QString path);
	void readOnly(QString path);
	void savePic(QString savePath);
	void copyPic(Picture* pic, Picture toCopy);

private:
	Picture newPic;
	Picture oldPic;

	Data();
	Data(const Data&);

};

#endif// DATA_H