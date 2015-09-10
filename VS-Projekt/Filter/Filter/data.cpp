#include "data.h"

Data::Data(){

}

Data::~Data(){

}

Picture Data::getPic(){
	return Picture(pic);
}

void Data::setPic(Picture newPic){
	pic.setWidth(newPic.getWidth());
	pic.setHeight(newPic.getHeight());
	pic.setMaxBright(newPic.getMaxBright());
	pic.setImage(newPic.getImage());
	pic.setPath(newPic.getPath());
	pic.setOnlyGray(newPic.isOnlyGray());
	pic.setColorData(newPic.getColorData());
	pic.setGrayData(newPic.getGrayData());
}

void Data::readPic(QString path){
	Picture read(path);
	pic.setWidth(read.getWidth());
	pic.setHeight(read.getHeight());
	pic.setMaxBright(read.getMaxBright());
	pic.setImage(read.getImage());
	pic.setPath(read.getPath());
	pic.setOnlyGray(read.isOnlyGray());
	pic.setColorData(read.getColorData());
	pic.setGrayData(read.getGrayData());
}

QImage Data::getImage(){
	return QImage(pic.getImage());
}