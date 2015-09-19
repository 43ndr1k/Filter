#ifndef PICTURE_H
#define PICTURE_H

#include <qimage.h>

class Picture
{

public:
	//Standart Konstruktor
	Picture();
	//Kompletter Konstruktor
	Picture(int width, int height, int maxBright, bool onlyGray, int*** colorData, int** grayData, QString path, QImage image);
	//Konstruktor mit Pfadangabe
	Picture(QString path);
	//Kopierkonstruktor
	Picture(const Picture& rhs);
	//Destruktor
	~Picture();

	//Funktionen
	/*Picture readPic(QString path);*/

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
	void setColorData(int*** colorData, int x, int y);
	void setGrayData(int** grayData, int x, int y);
	void setImage(QImage image);


private:
	int m_width;
	int m_height;
	int m_maxBright;
	bool m_onlyGray;
	QImage m_image;
	int*** m_colorData;
	int** m_grayData;
	QString m_path;

};

#endif// PICTURE_H