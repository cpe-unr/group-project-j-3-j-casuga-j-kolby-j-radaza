#ifndef NORMALIZER_H
#define NORMALIZER_H
#include "processor.h"
/**
 * This is the Echo Class that inherits from Processor 
 * Made by Justin Casuga
 */

class Normalizer: public Processor{

public:

	void process(int size, unsigned char* metaData);



};
#endif //NORMALIZER_H
