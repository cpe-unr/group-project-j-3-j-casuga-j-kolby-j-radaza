#ifndef PROCESSOR_H
#define PROCESSOR_H
/**
 * This is the Processor Abstract Class 
 * Made by Justin Casuga
 */

class Processor{

public:
	/**
	 * This function is abstract and virtual to allow child classes to inherit the method to handle 8 Bit Mono.
	 * @param size - The size of the array
	 * @param buffer - An unsigned char pointer that points to an array, one for Mono audio files
	 */
	virtual void processMono(int size, unsigned char* buffer) = 0;

	/**
	 * This function is abstrac and virtual to allow child classes to inherit the method to handle 8 Bit Stereo.
	 * @param sizeL - The size of the left side array
	 * @param sizeR - The size of the right side array
	 * @param bufferL - An unsigned char pointer that points to the left side array
	 * @param bufferR - An unsigned char pointer that points to the right side array 
	 */
	virtual void processStereo(int sizeL, int sizeR, unsigned char* bufferL, unsigned char* bufferR) = 0;
	
	/**
	 * This function is abstract and virtual to allow child classes to inherit the method to handle 16 Bit Mono.
	 * @param size - The size of the array
	 * @param buffer - An unsigned char pointer that points to an array, one for Mono audio files
	 */
	virtual void processMono(int size, short* buffer) = 0;
	
	/**
	 * This function is abstract and virtual to allow child classes to inherit the method to handle 16 Bit Stereo.
	 * @param sizeL - The size of the left side array
	 * @param sizeR - The size of the right side array
	 * @param bufferL - An unsigned char pointer that points to the left side array
	 * @param bufferR - An unsigned char pointer that points to the right side array 
	 */
	virtual void processStereo(int sizeL, int sizeR, short* bufferL, short* bufferR) = 0;

};

#endif //PROCESSOR_H
