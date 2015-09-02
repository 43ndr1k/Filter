#include "picture.h"

Picture::Picture(int height,int width){
	this->m_width = width;
	this->m_height = height;

	//Speicher für die Farbmatrix allokieren
	this->m_colorData = (int***) malloc(3*sizeof(int**));
	for (int c = 0; c < 3; c++)
	{
		this->m_colorData[c] = (int**)malloc(height * sizeof(int*));

		for (int i = 0; i < height; i++)
		{
			this->m_colorData[c][i] = (int*)malloc(width * sizeof(int));
		}
	}
	
	//Speicher für die Grauwertmatrix allokieren
	this->m_grayData = (int**)malloc(height*sizeof(int*));
	for (int i = 0; i < width; i++)
	{
		this->m_grayData[i] = (int*)malloc(width * sizeof(int));
	}
}

Picture::~Picture(){
	
	int width = this->m_width;

	//Farbmatrix freigeben
	for (int c = 0; c < 3; c++)
	{
		for (int i = 0; i < this->m_height; i++)
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
	free(m_colorData);
}

bool Picture::readPic(QString path){
	FILE* datei = fopen(path.toLocal8Bit().constData(), "r");
	m_image = QImage(path);
	if (datei == NULL){
		return false;
	}

	int count = 0;
	while (!(count > 3)){
		char* temp = readSymbol(datei);

		if (temp != NULL) {

			switch (count) {
			case 0:
				//Typ
				if (strcmp(temp,"P3")==0){
					setOnlyGray(false);
				}
				else{
					if (strcmp(temp, "P2") == 0){
						setOnlyGray(true);
					}
					else{
						//Kein gültiges Format
						return false;
					}
				}
				break;
			case 1:
				//Breite
				this->setWidth(atoi(temp));
				break;
			case 2:
				//Höhe
				this->setHeight(atoi(temp));
				break;
			case 3:
				//Maximale Helligkeit
				this->setMaxBright(atoi(temp));
				break;
			}
			count++;

		}
		else {
			//Ungültige Werte in Datei
			return false;
		}
		free(temp);
	}
	
	int i, j;

	for (i = 0; i < getHeight(); i++) {
		for (j = 0; j < getWidth(); j++) {
			if (!(isOnlyGray)) {
				m_colorData[0][i][j] = atoi(temp(datei));
				m_colorData[1][i][j] = atoi(temp(datei));
				m_colorData[2][i][j] = atoi(temp(datei));
				m_grayData[i][j] = (int)(0.299 * m_colorData[0][i][j] + 0.587 *m_colorData[1][i][j] + 0.114*m_colorData[2][i][j]);
			}
			else {
				m_grayData[i][j] = atoi(temp(datei));
			}
		}
	}

	return true;
}

//Liest und Speichert ein Symbol bis zum Leerzeichen
char* readSymbol(FILE* datei){
	// Temporärer String, der den eingelesenen
	// String speichert und später an die richtige
	// Variable kopiert.
	char puffer[] = "";
	char *str = (char*) malloc(strlen(puffer) + 1);
	size_t len = 0;

	//Wert auf 0 setzten
	memset(str, 0, (sizeof(str)));

	//Wort gueltig?
	int gueltig = 0;



	// Lesen von Zeichen für Zeichen
	while (!feof(datei)) {
		fread(puffer, sizeof(char), 1, datei);

		if (puffer[0] == ' ' || puffer[0] == '\n' || puffer[0] == '\r' || puffer[0] == '\t') {
			if (gueltig == 1) {
				len = strlen(str);
				str[len] = '\0';
				return str;
			}
		}
		else {
			gueltig = 1;
			strncat(str, puffer, sizeof(char));
			str = (char*) realloc(str, strlen(puffer) + len + 1);
		}

	}
	if (gueltig == 1) {
		len = strlen(str);
		str[len] = '\0';
		return str;
	}
	else {

	}
	return NULL;
}

// Speichert das aktuelle Wort zwischen und prüft ob das Wort Null ist
char *temp(FILE* datei) {
	char* temp = readSymbol(datei);
	if (temp != NULL) {
		return temp;
	}
	else {
		//Unlesbares Zeichen
	}
	return NULL;
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
	return this->isOnlyGray;
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
	int** grayData;
	//Speicher für neue Grauwertmatrix allokieren
	this->m_grayData = (int**)malloc(this->m_height*sizeof(int*));
	for (int i = 0; i < this->m_width; i++)
	{
		this->m_grayData[i] = (int*)malloc(this->m_width * sizeof(int));
	}

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