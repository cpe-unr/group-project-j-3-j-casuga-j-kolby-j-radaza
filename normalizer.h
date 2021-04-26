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

	void processMono(int size, unsigned char* buffer);
	
	void processStereo(int sizeL, int sizeR, unsigned char* bufferL, unsigned char* bufferR);

	void processMono(int size, short* buffer);

	void processStereo(int sizeL, int sizeR, short* bufferL, short* bufferR);


	Normalizer();
	Normalizer(int max);

	int getMax();
	void setMax(int nMax);

};
#endif //NORMALIZER_H
