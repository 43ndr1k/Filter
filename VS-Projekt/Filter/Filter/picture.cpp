#include "picture.h"
#include "ArrayFct.h"
#include "fileIO.h"
#include "string.h"

//Standartkonstruktor
Picture::Picture(){

}

//Kompletter Konstruktor
Picture::Picture(int width, int height, int maxBright, bool onlyGray, int*** colorData, int** grayData, QString path, QImage image){
	//Größe des Bildes speichern
	m_width = width;
	m_height = height;

	//Eigenschaften speichern
	m_maxBright = maxBright;
	m_onlyGray = onlyGray;

	//Umfangreichere Eigenschaften speichern
	m_path = QString(path);
	m_image = QImage(image);

	//Matrixen einspeichern
	m_colorData = ArrayFct::copy3DMatrix(colorData, 3, width, height);
	m_grayData = ArrayFct::copy2DMatrix(grayData, width, height);
}

//Konstruktor mit Pfadangabe
Picture::Picture(QString path){
	m_path = QString(path);

	FILE* datei = fopen(path.toLocal8Bit().constData(), "r");
	if (datei == NULL){
		//Fehlermeldung ergänzen
		//return false;
	}

	int count = 0;
	while (!(count > 3)){
		char* temp = FileIO::readSymbol(datei);

		if (temp != NULL) {

			switch (count) {
			case 0:
				//Typ
				if (strcmp(temp, "P3") == 0){
					m_onlyGray = false;
				}
				else{
					if (strcmp(temp, "P2") == 0){
						m_onlyGray = true;
					}
					else{
						//Kein gültiges Format
						//Fehlermeldung ergänzen
						//return false;
					}
				}
				break;
			case 1:
				//Breite
				m_width = atoi(temp);
				break;
			case 2:
				//Höhe
				m_height = atoi(temp);
				break;
			case 3:
				//Maximale Helligkeit
				m_maxBright = atoi(temp);
				break;
			}
			count++;

		}
		else {
			//Ungültige Werte in Datei
			//Fehlermeldung ergänzen
			//return false;
		}
		free(temp);
	}

	m_colorData = ArrayFct::allocate3DMatrix(3, m_width, m_height);
	m_grayData = ArrayFct::allocate2DMatrix(m_width, m_height);

	for (int xz = 0; xz < m_width; xz++) {
		for (int yz = 0; yz < m_height; yz++) {
			if (!m_onlyGray) {
				m_colorData[0][xz][yz] = atoi(FileIO::temp(datei));
				m_colorData[1][xz][yz] = atoi(FileIO::temp(datei));
				m_colorData[2][xz][yz] = atoi(FileIO::temp(datei));
				m_grayData[xz][yz] = 0.299 * m_colorData[0][xz][yz] + 0.587 *m_colorData[1][xz][yz] + 0.114*m_colorData[2][xz][yz];
			}
			else {
				m_grayData[xz][yz] = atoi(FileIO::temp(datei));
			}
		}
	}
	fclose(datei);
	m_image = QImage(path);
}

//Kopierkonstruktor
Picture::Picture(const Picture& rhs){
	m_width = rhs.m_width;
	m_height = rhs.m_height;
	m_maxBright = rhs.m_maxBright;
	m_onlyGray = rhs.m_onlyGray;
	m_image = QImage(rhs.m_image);
	m_path = QString(rhs.m_path);

	//Kopieren der Farbmatrix
	m_colorData = ArrayFct::copy3DMatrix(rhs.m_colorData, 3, m_width, m_height);

	//Kopieren der Grauwertmatrix
	m_grayData = ArrayFct::copy2DMatrix(rhs.m_grayData, m_width, m_height);
}

//Destruktor
Picture::~Picture(){
	//Farbmatrix freigeben
	ArrayFct::free3DMatrix(m_colorData);

	//Speicher für Grauwertmatrix freigeben
	ArrayFct::free2DMatrix(m_grayData);
}

//Setzt die Höhe des Bildes
void Picture::setHeight(int height){
	m_height = height;
}

//Setzt die Breite des Bildes
void Picture::setWidth(int width){
	m_width = width;
}

//Setzt die maximale Helligkeit im Bild
void Picture::setMaxBright(int maxBright){
	m_maxBright = maxBright;
}

//Setzt das Flag ob Grauwertbild
void Picture::setOnlyGray(bool onlyGray){
	m_onlyGray = onlyGray;
}

//Setzt den Pfad des Bildes
void Picture::setPath(QString path){
	m_path = QString (path);
}

//Setzt das Anzeigebild
void Picture::setImage(QImage image){
	this->m_image = QImage(image);
}

//Setzt die Farbmatrix des Bildes
void Picture::setColorData(int*** colorData){
	m_colorData = ArrayFct::copy3DMatrix(colorData, 3, m_width, m_height);
}

//Setzt die Graumatrix des Bildes
void Picture::setGrayData(int** grayData){
	m_grayData = ArrayFct::copy2DMatrix(grayData, m_width, m_height);
}

//Gibt die Höhe des Bildes
int Picture::getHeight(){
	return m_height;
}

//Gibt die Breite des Bildes
int Picture::getWidth(){
	return m_width;
}

//Gibt die Maximale Helligkeit des Bildes
int Picture::getMaxBright(){
	return m_maxBright;
}

//Zeigt ob Grauwertbild
bool Picture::isOnlyGray(){
	return m_onlyGray;
}

//Gibt den Pfad des Bildes
QString Picture::getPath(){
	return QString(m_path);
}

//Gibt das Anzeigebild
QImage Picture::getImage(){
	return QImage(m_image);
}

//Gibt die Farbmatrix
int*** Picture::getColorData(){
	return ArrayFct::copy3DMatrix(m_colorData, 3, m_width, m_height);;
}

//Gibt die Grauwertmatrix
int** Picture::getGrayData(){
	return ArrayFct::copy2DMatrix(m_grayData, m_width, m_height);;
}