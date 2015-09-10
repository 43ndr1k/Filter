#include <fileIo.h>
#include <stdlib.h>
#include <string.h>


//Liest und Speichert ein Symbol bis zum Leerzeichen
char* FileIO::readSymbol(FILE* datei){
	// Temporärer String, der den eingelesenen
	// String speichert und später an die richtige
	// Variable kopiert.

	char* puffer = (char*)malloc(sizeof(char));
	//char puffer[] = "";

	char *str = (char*)malloc(strlen(puffer) + 1);
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
			str = (char*)realloc(str, strlen(puffer) + len + 1);
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
char* FileIO::temp(FILE* datei) {
	char* temp = FileIO::readSymbol(datei);
	if (temp != NULL) {
		return temp;
	}
	else {
		//Unlesbares Zeichen
	}
	return NULL;
}