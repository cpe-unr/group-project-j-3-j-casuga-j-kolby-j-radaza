#ifndef SIXTEEN_BIT_STEREO_H
#define SIXTEEN_BIT_STEREO_H
#include <fstream>
#include "header.h"
/**
 * This is the 16 Bit Stereo Class that inherits from header
 * Made by James Kolby
 */

class Stereo16Bit : public header{
public:
	waveHeader fileHeader;
	
	/**
 	* This is the default constructor.
 	*/
	Stereo16Bit();
	
	/**
 	* This is the default destructor.
 	*/
	~Stereo16Bit();
	
	/**
	 * This function reads audio data from a given fstream object.
	 * @param *file - The ifstream object of the file to be read.
	 * @param *bufferL - The short array for the left channel
	 * @param *bufferL - The short array for the right channel
	 */
	void readAudio(std::ifstream *file, short *bufferL, short *bufferR);
	
	/**
	 * This function writes audio data to a given fstream object.
	 * @param *file - The ifstream object of the file to be written to.
	 * @param *bufferL - The short array for the left channel
	 * @param *bufferL - The short array for the right channel
	 */
	void writeAudio(std::ofstream *file, short *bufferL, short *bufferR);
};
#endif
