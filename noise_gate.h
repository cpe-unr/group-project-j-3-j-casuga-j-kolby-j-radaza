#ifndef NOISE_GATE_H
#define NOISE_GATE_H
#include "processor.h"
/**
 * This is the Noise Gate Class that inherits from Processor 
 * Made by Justin Casuga
 */

class NoiseGate: public Processor{

public:

	void process(int size, unsigned char* metaData);



};
#endif //NOISE_GATE_H
