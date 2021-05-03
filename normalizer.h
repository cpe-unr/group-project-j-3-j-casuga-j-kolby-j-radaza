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

	/**
 	* This is the inherited abstract function from processor that is overidded to handle 8 bit mono normalizer processing
 	*/
	void processMono(int size, unsigned char* buffer);

	/**
 	 * This is the inherited abstract function from processor that is overidded to handle 8 bit stereo normalizer processing
	 */	
	void processStereo(int size, unsigned char* bufferL, unsigned char* bufferR);

	/**
 	 * This is the inherited abstract function from processor that is overidded to handle 16 bit mono normalizer processing
	 */
	void processMono(int size, short* buffer);

	/**
 	 * This is the inherited abstact function from processsor that is overidded to handle 16 bit stereo normalizer processing
	 */
	void processStereo(int size, short* bufferL, short* bufferR);

	/**
	 * This is Normalizers default constructor
	 */
	Normalizer();

	/**
	 * This is Normalizers parameterized constructor
	 * @param max - The max value that will affect normalization
	 */
	Normalizer(int max);

	/**
	 * This is Normalizers getter for the private attribute max
	 */
	int getMax();

	/**
	 * This is Normalizers setter for the private attribute max\
	 * @param nMax - The max that gets passed in
	 */
	void setMax(int nMax);

};
#endif //NORMALIZER_H
