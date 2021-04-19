#ifndef PROCESSOR_H
#define PROCESSOR_H
/**
 * This is the Processor Abstract Class 
 * Made by Justin Casuga
 */

class Processor{

public:
	virtual void process(int size, unsigned char* metaData) = 0;


};
#endif //PROCESSOR_H
