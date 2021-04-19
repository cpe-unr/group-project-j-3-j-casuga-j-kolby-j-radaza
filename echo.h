#ifndef ECHO_H
#define ECHO_H
#include "processor.h"
/**
 * This is the Echo Class that inherits from Processor 
 * Made by Justin Casuga
 */

class Echo: public Processor{

public:

	void process(int size, unsigned char* metaData);


};
#endif //ECHO_H
