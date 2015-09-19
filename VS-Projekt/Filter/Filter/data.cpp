#include "data.h"

Data::Data(){

}

Data& Data::getInstance(){
	static Data instance;
	return instance;
}

Picture Data::getPic(){
	return Picture(newPic);
}

Picture Data::getLastPic(){
	return Picture(oldPic);
}

void Data::setPic(Picture pic){
	copyPic(&oldPic, newPic);
	copyPic(&newPic, pic);
}

void Data::readPic(QString path){
	copyPic(&oldPic, newPic);
	copyPic(&newPic, Picture (path));
}

void Data::readOnly(QString path){
	copyPic(&newPic, Picture(path));
}

void Data::savePic(QString savePath){
	FILE *fp;

	fp = fopen(savePath.toLocal8Bit().constData(), "w");
	if (fp == NULL) {
		//Entsprechende Fehlerbehandlung einfügen
	}
	else {
		if (!newPic.isOnlyGray()){
			int i, j, width, height;
			width = newPic.getWidth();
			height = newPic.getHeight();
			char puffer[10];
			char R[10], G[10], B[10];

			fprintf(fp, "P3");
			fprintf(fp, "\n");
			sprintf(puffer, "%d", newPic.getWidth());
			fprintf(fp, "%s", puffer);
			fprintf(fp, " ");
			sprintf(puffer, "%d", newPic.getHeight());
			fprintf(fp, "%s", puffer);
			fprintf(fp, "\n");
			sprintf(puffer, "%d", newPic.getMaxBright());
			fprintf(fp, "%s", puffer);
			fprintf(fp, "\n");

			int*** color = newPic.getColorData();

			for (int h = 0; h < height; h++){
				for (int w = 0; w < width; w++){
					fprintf(fp, "%4i %4i %4i ", color[0][w][h], color[1][w][h], color[2][w][h]);
				}
				fprintf(fp, "\n");
			}
		}
		else{
			int i, j, width, height;
			width = newPic.getWidth();
			height = newPic.getHeight();
			char puffer[10];
			fprintf(fp, "P2");
			fprintf(fp, "\n");
			sprintf(puffer, "%d", newPic.getWidth());
			fprintf(fp, "%s", puffer);
			fprintf(fp, " ");
			sprintf(puffer, "%d", newPic.getHeight());
			fprintf(fp, "%s", puffer);
			fprintf(fp, "\n");
			sprintf(puffer, "%d", newPic.getMaxBright());
			fprintf(fp, "%s", puffer);
			fprintf(fp, "\n");

			int** gray = newPic.getGrayData();

			for (int h = 0; h < height; h++){
				for (int w = 0; w < width; w++){
					fprintf(fp, "%2i ", gray[w][h]);
				}
				fprintf(fp, "\n");
			}
		}
		

		fclose(fp);
	}
}

QImage Data::getImage(){
	return QImage(newPic.getImage());
}

void Data::copyPic(Picture* pic, Picture toCopy){
	pic->setMaxBright(toCopy.getMaxBright());
	pic->setImage(toCopy.getImage());
	pic->setPath(toCopy.getPath());
	pic->setOnlyGray(toCopy.isOnlyGray());
	pic->setColorData(toCopy.getColorData(), toCopy.getWidth(), toCopy.getHeight());
	pic->setGrayData(toCopy.getGrayData(), toCopy.getWidth(), toCopy.getHeight());
	pic->setWidth(toCopy.getWidth());
	pic->setHeight(toCopy.getHeight());
}