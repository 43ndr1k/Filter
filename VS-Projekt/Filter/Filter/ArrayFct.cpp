#include "ArrayFct.h"
#include <stdlib.h>

//Funktion zum allokieren von Speicher einer 3D Matrix
//z = Ebenen , x = X-Ausdehnung, y = Y-Ausdehnung
int*** ArrayFct::allocate3DMatrix(int z, int x, int y){
	int *** matrix = (int***)malloc(z * sizeof(int**));

	for (int c = 0; c < z; c++)
	{
		matrix[c] = allocate2DMatrix(x, y);
	}
	return matrix;
}

//Funktion zum allkoieren von Speicher einer 2D Matrix
//x = X-Ausdehnung, y = Y-Ausdehnung
int** ArrayFct::allocate2DMatrix(int x, int y){
	int** matrix = (int**)malloc(x*sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		matrix[i] = (int*)malloc(y * sizeof(int));
	}
	return matrix;
}

//Funktion zum freigeben von Speicher einer 3D Matrix
void ArrayFct::free3DMatrix(int*** matrix, int z, int x){
	for (int c = 0; c < z; c++)
	{
		free2DMatrix(matrix[c], x);
	}

	free(matrix);
}

//Funktion zum freigeben von Speicher einer 2D Matrix
void ArrayFct::free2DMatrix(int** matrix, int x){
	for (int i = 0; i < x; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

//Funktion zum kopieren einer 3D Matrix
int*** ArrayFct::copy3DMatrix(int*** matrix, int z, int x, int y){
	int*** copy = (int***) malloc (z * sizeof(int**));

	for (int zz = 0; zz < z; zz++)
	{
		copy[zz] = copy2DMatrix(matrix[zz], x, y);
	}
	return copy;
}

//Funktion zum kopieren einer 2D Matrix
int** ArrayFct::copy2DMatrix(int** matrix, int x, int y){
	int** copy = allocate2DMatrix(x, y);

	for (int xz = 0; xz < x; xz++)
	{
		for (int yz = 0; yz < y; yz++){
			copy[xz][yz] = matrix[xz][yz];
		}
	}
	return copy;
}