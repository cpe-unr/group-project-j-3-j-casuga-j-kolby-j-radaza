#ifndef ECHO_H
#define ECHO_H
#include "processor.h"
/**
 * This is the Echo Class that inherits from Processor 
 * Made by Justin Casuga
 */

class Echo: public Processor{

int delay;

public:

	void processMono(int size, unsigned char* metaData);
	
	void processStereo(int sizeL, int sizeR, unsigned char* metaDataL, unsigned char* metaDataR);

	Echo();
	Echo(int nDelay);

	int getDelay();
	void setDelay(int nDelay);

};
#endif //ECHO_H
