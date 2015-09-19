#ifndef ARRAYFCT_H
#define ARRAYFCT_H

class ArrayFct
{

public:

	//Funktion zum allokieren von Speicher einer 3D Matrix
	//z = Ebenen , x = X-Ausdehnung, y = Y-Ausdehnung
	static int*** allocate3DMatrix(int z, int x, int y);

	//Funktion zum allkoieren von Speicher einer 2D Matrix
	//x = X-Ausdehnung, y = Y-Ausdehnung
	static int** allocate2DMatrix(int x, int y);

	//Funktion zum freigeben von Speicher einer 3D Matrix
	static void free3DMatrix(int*** matrix, int z, int x);

	//Funktion zum freigeben von Speicher einer 2D Matrix
	static void free2DMatrix(int** matrix, int x);

	//Funktion zum kopieren einer 3D Matrix
	static int*** copy3DMatrix(int*** matrix, int z, int x, int y);

	//Funktion zum kopieren einer 2D Matrix
	static int** copy2DMatrix(int** matrix, int x, int y);

private:


};

#endif// ARRAYFCT_H