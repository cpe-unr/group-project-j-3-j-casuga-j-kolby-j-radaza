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

	/**
 	* This is the inherited abstract function from processor that is overidded to handle 8 bit mono echo processing
 	*/
	void processMono(int size, unsigned char* buffer);
	
	/**
 	 * This is the inherited abstract function from processor that is overidded to handle 8 bit stereo echo processing
	 */
	void processStereo(int size, unsigned char* bufferL, unsigned char* bufferR);

	/**
 	 * This is the inherited abstract function from processor that is overidded to handle 16 bit mono echo processing
	 */
	void processMono(int size, short* buffer);

	/**
 	 * This is the inherited abstact function from processsor that is overidded to handle 16 bit stereo echo processing
	 */
	void processStereo(int size, short* bufferL, short* bufferR);

	/**
 	 * This is Echo's default constructor
	 */
	Echo();

	/**
 	 * This is Echo's parameterized constructor
	 * @param nDelay - the delay that affects the echo processing
	 */
	Echo(int nDelay);

	/**
 	 * This is Echo's getter for the private attribute Delay
	 */
	int getDelay();

	/**
 	 * This is Echo's setter for the private attribute Delay
	 * @param nDelay - the delay that is passed in 
	 */
	void setDelay(int nDelay);

};
#endif //ECHO_H
