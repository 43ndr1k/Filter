#ifndef FILTERASM_H
#define FILTERASM_H


class FilterASM
{

public:
	void threshold(int** grayData, int width, int height, int limit, int max, int min);
	void meanValue(int** grayData, int width, int height, int** erg);

private:

};

#endif// FILTERASM_H