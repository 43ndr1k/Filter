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

void Data::savePic(QString savePath){
	FILE *fp;

	fp = fopen(savePath.toLocal8Bit().constData(), "w");
	if (fp == NULL) {
		//Entsprechende Fehlerbehandlung einfügen
	}
	else {

		int i, j, width, height;
		width = pic.getWidth();
		height = pic.getHeight();
		char puffer[10];
		char R[10], G[10], B[10];

		fprintf(fp, "P3");
		fprintf(fp, "\n");
		sprintf(puffer, "%d", pic.getWidth());
		fprintf(fp, "%s", puffer);
		fprintf(fp, " ");
		sprintf(puffer, "%d", pic.getHeight());
		fprintf(fp, "%s", puffer);
		fprintf(fp, "\n");
		sprintf(puffer, "%d", pic.getMaxBright());
		fprintf(fp, "%s", puffer);
		fprintf(fp, "\n");

		int*** color = pic.getColorData();

		for (int h = 0; h < height; h++){
			for (int w = 0; w < width; w++){
				fprintf(fp, "%4i %4i %4i ", color[0][w][h], color[1][w][h], color[2][w][h]);
			}
			fprintf(fp, "\n");
		}

		fclose(fp);
	}
}

QImage Data::getImage(){
	return QImage(pic.getImage());
}