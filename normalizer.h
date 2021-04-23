#ifndef NORMALIZER_H
#define NORMALIZER_H
#include "processor.h"
/**
 * This is the Echo Class that inherits from Processor 
 * Made by Justin Casuga
 */

class Normalizer: public Processor{

int max;
public:

	void process(int size, unsigned char* metaData);
	
	void processStereo(int sizeL, int sizeR, unsigned char* metaDataL, unsigned char* metaDataR);

	Normalizer();
	Normalizer(int max);

	int getMax();
	void setMax(int nMax);

};
#endif //NORMALIZER_H
