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

private:
	Data* myData;
	FilterASM* filter;
	Options();
	Options(const Options&);

	void saveResult();
};

#endif// OPTIONS_H