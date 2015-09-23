#ifndef OPTIONS_H
#define OPTIONS_H

#include "data.h"
#include "FilterASM.h"

class Options
{

public:
	static Options& getInstance();

	void makeGray();
	void threshold();
	void thresholdSobel();
	void meanValue();
	void gauss();
	void hSobel();
	void vSobel();
	void qSobel();
	void kSobel();

private:
	Data* myData;
	FilterASM* filter;
	Options();
	Options(const Options&);

	void saveResult();
};

#endif// OPTIONS_H