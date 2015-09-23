#include "options.h"
#include "ArrayFct.h"

Options& Options::getInstance(){
	static Options instance;
	return instance;
}

Options::Options(){
	myData = &Data::getInstance();
	filter = &FilterASM();
}

void Options::makeGray(){
	Picture pic = myData->getPic();
	pic.setOnlyGray(true);
	myData->setPic(pic);
	saveResult();
}

void Options::threshold(){
	Picture pic = myData->getPic();
	pic.setOnlyGray(true);
	int** grayData = pic.getGrayData();
	int width = pic.getWidth();
	int height = pic.getHeight();
	filter->threshold(grayData, width, height, 50, pic.getMaxBright(), 0);
	pic.setGrayData(grayData, width, height);
	myData->setPic(pic);
	saveResult();
}

void Options::thresholdSobel(){
	Picture pic = myData->getPic();
	pic.setOnlyGray(true);
	int** grayData = pic.getGrayData();
	int width = pic.getWidth();
	int height = pic.getHeight();
	filter->threshold(grayData, width, height, 20, pic.getMaxBright(), 0);
	pic.setGrayData(grayData, width, height);
	myData->setPic(pic);
	saveResult();
}

void Options::meanValue(){
	Picture pic = myData->getPic();
	pic.setOnlyGray(true);
	int** grayData = pic.getGrayData();
	int width = pic.getWidth();
	int height = pic.getHeight();
	int** erg = ArrayFct::copy2DMatrix(grayData, width, height);
	filter->meanValue(grayData, width, height, erg);
	pic.setGrayData(erg, width, height);
	myData->setPic(pic);
	saveResult();
}

void Options::gauss(){
	Picture pic = myData->getPic();
	pic.setOnlyGray(true);
	int** grayData = pic.getGrayData();
	int width = pic.getWidth();
	int height = pic.getHeight();
	int** erg = ArrayFct::copy2DMatrix(grayData, width, height);
	filter->gauss(grayData, width, height, erg);
	pic.setGrayData(erg, width, height);
	myData->setPic(pic);
	saveResult();
}

void Options::hSobel(){
	Picture pic = myData->getPic();
	pic.setOnlyGray(true);
	int** grayData = pic.getGrayData();
	int width = pic.getWidth();
	int height = pic.getHeight();
	int** erg = ArrayFct::copy2DMatrix(grayData, width, height);
	int matrix[9] = { 1, 2, 1, 0, 0, 0, -1, -2, -1 };
	filter->easySobel(grayData, width, height, erg, &matrix[0]);
	pic.setGrayData(erg, width, height);
	myData->setPic(pic);
	saveResult();
}

void Options::kSobel(){
	Picture pic = myData->getPic();
	pic.setOnlyGray(true);
	int** grayData = pic.getGrayData();
	int width = pic.getWidth();
	int height = pic.getHeight();
	int** erg1 = ArrayFct::copy2DMatrix(grayData, width, height);
	int** erg2 = ArrayFct::copy2DMatrix(grayData, width, height);
	int** gErg = ArrayFct::copy2DMatrix(grayData, width, height);
	int matrix1[9] = { 1, 2, 1, 0, 0, 0, -1, -2, -1 };
	filter->easySobel(grayData, width, height, erg1, &matrix1[0]);
	int matrix2[9] = { 1, 0, -1, 2, 0, -2, 1, 0, -1 };
	filter->easySobel(grayData, width, height, erg2, &matrix2[0]);
	filter->Sobel(erg1, erg2, width, height, gErg);
	pic.setGrayData(gErg, width, height);
	myData->setPic(pic);
	saveResult();
}

void Options::vSobel(){
	Picture pic = myData->getPic();
	pic.setOnlyGray(true);
	int** grayData = pic.getGrayData();
	int width = pic.getWidth();
	int height = pic.getHeight();
	int** erg = ArrayFct::copy2DMatrix(grayData, width, height);
	int matrix[9] = { 1, 0, -1, 2, 0, -2, 1, 0, -1 };
	filter->easySobel(grayData, width, height, erg, &matrix[0]);
	pic.setGrayData(erg, width, height);
	myData->setPic(pic);
	saveResult();
}

void Options::qSobel(){
	Picture pic = myData->getPic();
	pic.setOnlyGray(true);
	int** grayData = pic.getGrayData();
	int width = pic.getWidth();
	int height = pic.getHeight();
	int** erg = ArrayFct::copy2DMatrix(grayData, width, height);
	int matrix[9] = { 2, 1, 0, 1, 0, -1, 0, -1, -2 };
	filter->easySobel(grayData, width, height, erg, &matrix[0]);
	pic.setGrayData(erg, width, height);
	myData->setPic(pic);
	saveResult();
}

void Options::saveResult(){
	myData->savePic("temp.ppm");
	myData->readOnly("temp.ppm");
}