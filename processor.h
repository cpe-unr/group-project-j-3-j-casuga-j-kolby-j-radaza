#ifndef PROCESSOR_H
#define PROCESSOR_H
/**
 * This is the Processor Abstract Class 
 * Made by Justin Casuga
 */

class Processor{

public:
	/**
	 * This function is abstract and virtual to allow child classes to inherit the method to handle Mono.
	 * @param size - The size of the array
	 * @param metaData - An unsigned char pointer that points to an array, one for Mono audio files
	 */
	virtual void processMono(int size, unsigned char* metaData) = 0;

	/**
	 * This function is abstrac and virtual to allow child classes to inherit the method to handle Stereo.
	 * @param sizeL - The size of the left side array
	 * @param sizeR - The size of the right side array
	 * @param metaDataL - An unsigned char pointer that points to the left side array
	 * @param metaDataR - An unsigned char pointer that points to the right side array 
	 */
	virtual void processStereo(int sizeL, int sizeR, unsigned char* metaDataL, unsigned char* metaDataR) = 0;
	


};
#endif //PROCESSOR_H
