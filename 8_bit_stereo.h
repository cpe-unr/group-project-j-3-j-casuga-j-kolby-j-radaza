#ifndef EIGHT_BIT_STEREO
#define EIGHT_BIT_STEREO
#include <fstream>
#include "header.h"
/**
 * This is the 8 Bit Stereo Class that inherits from header
 * Made by James Kolby
 */

class Stereo8Bit : public header{
public:
	waveHeader fileHeader;
	
	/**
 	* This is the default constructor.
 	*/
	Stereo8Bit();
	
	/**
 	* This is the default destructor.
 	*/
	~Stereo8Bit();
	
	/**
	 * This function reads audio data from a given fstream object.
	 * @param *file - The ifstream object of the file to be read.
	 * @param *bufferL - The unsigned char* array for the left channel
	 * @param *bufferL - The unsigned char* array for the right channel
	 */
	void readAudio(std::ifstream *file, unsigned char *bufferL, unsigned char *bufferR);
	
	/**
	 * This function writes audio data to a given fstream object.
	 * @param *file - The ifstream object of the file to be written to.
	 * @param *bufferL - The unsigned char* array for the left channel
	 * @param *bufferL - The unsigned char* array for the right channel
	 */
	void writeAudio(std::ofstream *file, unsigned char *bufferL, unsigned char *bufferR);
};
#endif
