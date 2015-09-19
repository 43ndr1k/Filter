#include "options.h"

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

void Options::saveResult(){
	myData->savePic("temp.ppm");
	myData->readOnly("temp.ppm");
}