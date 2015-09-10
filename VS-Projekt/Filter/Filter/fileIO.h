#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>

class FileIO
{

public:
	static char* readSymbol(FILE* datei);
	static char* temp(FILE* datei);

};

#endif// FILEIO_H