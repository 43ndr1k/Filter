#ifndef DATA_H
#define DATA_H

#include "picture.h"

class Data
{

public:
	Data();		//Konstruktor
	~Data();	//Destruktor

	Picture getPic();
	QImage getImage();

	void setPic(Picture pic);
	void readPic(QString path);
	void savePic(QString savePath);

private:
	Picture pic;

};

#endif// DATA_H