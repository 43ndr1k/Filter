#include "data.h"

Data::Data(){
	this->Pic = (Picture*)malloc(sizeof(Picture));
}

Data::~Data(){

}

Picture Data::getPic(){
	Picture copy(*this->Pic);
	return copy;
}

void Data::setPic(Picture pic){
	Picture copy(pic);
	this->Pic = &copy;
}

void Data::readPic(QString path){
	this->Pic = &this->Pic->readPic(path);
}

QImage Data::getImage(){
	QImage copy(this->Pic->getImage());
	return copy;
}