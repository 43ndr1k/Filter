#ifndef FILTERASM_H
#define FILTERASM_H


class FilterASM
{

public:
	void threshold(int** grayData, int width, int height, int limit, int max, int min);
	void meanValue(int** grayData, int width, int height, int** erg);
	void gauss(int** grayData, int width, int height, int** erg);
	void easySobel(int** grayData, int width, int height, int** erg, int* matrix);
	void Sobel(int**matrix1, int** matrix2, int width, int height, int** erg);

private:

};

#endif// FILTERASM_H