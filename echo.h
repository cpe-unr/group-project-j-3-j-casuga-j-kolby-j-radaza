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

	void processMono(int size, unsigned char* buffer);
	
	void processStereo(int sizeL, int sizeR, unsigned char* bufferL, unsigned char* bufferR);

	void processMono(int size, unsigned short* buffer);

	void processStereo(int sizeL, int sizeR, unsigned short* bufferL, unsigned short* bufferR);


	Echo();
	Echo(int nDelay);

	int getDelay();
	void setDelay(int nDelay);

};
#endif //ECHO_H
