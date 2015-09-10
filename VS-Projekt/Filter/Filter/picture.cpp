#include "picture.h"
#include <fileIO.h>
#include <stdlib.h>

Picture::Picture(int width, int height){
	//Größe des Bildes speichern
	this->m_width = width;
	this->m_height = height;

	//Speicher für die Farbmatrix allokieren
	this->m_colorData = Picture::allocate3DMatrix(3, width, height);

	//Speicher für die Grauwertmatrix allokieren
	this->m_grayData = Picture::allocate2DMatrix(width, height);
}

Picture::~Picture(){

	int width = this->m_width;

	//Farbmatrix freigeben
	for (int c = 0; c < 3; c++)
	{
		for (int i = 0; i < width; i++)
		{
			free(this->m_colorData[c][i]);
		}
	}
	free(this->m_colorData[0]);
	free(this->m_colorData[1]);
	free(this->m_colorData[2]);
	free(this->m_colorData);

	//Speicher für Grauwertmatrix freigeben
	for (int i = 0; i < width; i++)
	{
		free(m_grayData[i]);
	}
	free(m_grayData);
}

Picture Picture::readPic(QString path){
	//m_image = QImage(path);

	//Variablen vorbereiten
	int width = 0;
	int height = 0;
	int maxBright = 0;
	bool onlyGray = false;


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
					onlyGray = false;
				}
				else{
					if (strcmp(temp, "P2") == 0){
						onlyGray = true;
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
				width = atoi(temp);
				break;
			case 2:
				//Höhe
				height = atoi(temp);
				break;
			case 3:
				//Maximale Helligkeit
				maxBright = atoi(temp);
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

	Picture pic(width, height);
	pic.setOnlyGray(onlyGray);
	pic.setMaxBright(maxBright);

	int i, j;

	for (i = 0; i < height - 1; i++) {
		for (j = 0; j < width - 1; j++) {
			if (!onlyGray) {
				pic.m_colorData[0][i][j] = atoi(FileIO::temp(datei));
				pic.m_colorData[1][i][j] = atoi(FileIO::temp(datei));
				pic.m_colorData[2][i][j] = atoi(FileIO::temp(datei));
				pic.m_grayData[i][j] = (int)(0.299 * pic.m_colorData[0][i][j] + 0.587 *pic.m_colorData[1][i][j] + 0.114*pic.m_colorData[2][i][j]);
			}
			else {
				pic.m_grayData[i][j] = atoi(FileIO::temp(datei));
			}
		}
	}
	fclose(datei);
	pic.setImage(QImage(path));
	return pic;
}




//Getter und Setter

void Picture::setHeight(int height){
	this->m_height = height;
}

void Picture::setWidth(int width){
	this->m_width = width;
}

void Picture::setMaxBright(int maxBright){
	this->m_maxBright = maxBright;
}

void Picture::setOnlyGray(bool onlyGray){
	this->m_onlyGray = onlyGray;
}

void Picture::setPath(QString path){
	this->m_path = path;
}

void Picture::setColorData(int*** colorData){
	for (int c = 0; c < 3; c++)
	{
		for (int i = 0; i < this->m_height; i++)
		{
			for (int j = 0; j < this->m_width; j++)
			{
				colorData[c][i][j] = this->m_colorData[c][i][j]; //Farbe, Höhe, Weite
			}
		}
	}
}

void Picture::setGrayData(int** grayData){
	for (int i = 0; i < this->m_height; i++)
	{
		for (int j = 0; j < this->m_width; j++)
		{
			grayData[i][j] = this->m_grayData[i][j]; // Höhe, Weite
		}
	}
}

void Picture::setImage(QImage image){
	this->m_image = image;
}

int Picture::getHeight(){
	return this->m_height;
}

int Picture::getWidth(){
	return this->m_width;
}

int Picture::getMaxBright(){
	return this->m_maxBright;
}

bool Picture::isOnlyGray(){
	return this->m_onlyGray;
}

QString Picture::getPath(){
	return this->m_path;
}

int*** Picture::getColorData(){
	int*** colorData;
	//Speicher für neue Farbmatrix allokieren
	colorData = (int***)malloc(3 * sizeof(int**));
	for (int c = 0; c < 3; c++)
	{
		colorData[c] = (int**)malloc(this->m_height * sizeof(int*));

		for (int i = 0; i < this->m_height; i++)
		{
			colorData[c][i] = (int*)malloc(this->m_width * sizeof(int));
		}
	}

	//Daten kopieren
	for (int c = 0; c < 3; c++)
	{
		for (int i = 0; i < this->m_height; i++)
		{
			for (int j = 0; j < this->m_width; j++)
			{
				colorData[c][i][j] = this->m_colorData[c][i][j]; //Farbe, Höhe, Weite
			}
		}
	}
	return colorData;
}

int** Picture::getGrayData(){
	//Speicher für neue Grauwertmatrix allokieren
	int** grayData = Picture::allocate2DMatrix(m_width, m_height);

	//Daten kopieren
	for (int i = 0; i < this->m_height; i++)
	{
		for (int j = 0; j < this->m_width; j++)
		{
			grayData[i][j] = this->m_grayData[i][j]; // Höhe, Weite
		}
	}
	return grayData;
}

QImage Picture::getImage(){
	return this->m_image;
}

//Funktion zum allokieren von Speicher einer 3D Matrix
//z = Ebenen , x = X-Ausdehnung, y = Y-Ausdehnung
int*** Picture::allocate3DMatrix(int z, int x, int y){
	int *** matrix = (int***)malloc(z * sizeof(int**));

	for (int c = 0; c < z; c++)
	{
		matrix[c] = (int**)malloc(x * sizeof(int*));

		for (int i = 0; i < x; i++)
		{
			matrix[c][i] = (int*)malloc(y * sizeof(int));
		}
	}
	return matrix;
}

//Funktion zum allkoieren von Speicher einer 2D Matrix
//x = X-Ausdehnung, y = Y-Ausdehnung
int** Picture::allocate2DMatrix(int x, int y){
	int** matrix = (int**)malloc(x*sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		matrix[i] = (int*)malloc(y * sizeof(int));
	}
	return matrix;
}