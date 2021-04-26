#ifndef NOISE_GATE_H
#define NOISE_GATE_H
#include "processor.h"
/**
 * This is the Noise Gate Class that inherits from Processor 
 * Made by Justin Casuga
 */

class NoiseGate: public Processor{

double amp;
public:


	void processMono(int size, unsigned char* buffer);
	
	void processStereo(int sizeL, int sizeR, unsigned char* bufferL, unsigned char* bufferR);

	void processMono(int size, short* buffer);

	void processStereo(int sizeL, int sizeR, short* bufferL, short* bufferR);

	NoiseGate();
	NoiseGate(double nAmp);

	double getAmp();
	void setAmp(double nAmp);

};
#endif //NOISE_GATE_H
