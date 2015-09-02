#ifndef PICTURE_H
#define PICTURE_H

#include <qimage.h>

class Picture
{

public:
	Picture(int width, int height);	//Konstruktor
	~Picture();	//Destruktor

	//Funktionen
	bool readPic(QString path);

	//Getter
	int getHeight();
	int getWidth();
	int getMaxBright();
	bool isOnlyGray();
	QString getPath();
	int*** getColorData();
	int** getGrayData();
	QImage getImage();

	//Setter
	void setHeight(int height);
	void setWidth(int width);
	void setMaxBright(int maxBright);
	void setOnlyGray(bool onlyGray);
	void setPath(QString path);
	void setColorData(int*** colorData);
	void setGrayData(int** grayData);
	void setImage(QImage image);


private:
	int m_width;
	int m_height;
	int m_maxBright;
	bool m_onlyGray;
	QImage m_image;
	int*** m_colorData; //R , G , B
	int** m_grayData;
	QString m_path;

};

#endif// PICTURE_H