#ifndef SIXTEEN_BIT_MONO_H
#define SIXTEEN_BIT_MONO_H
#include <fstream>
#include "header.h"
#include "metadata_io.h"
/**
 * This is the 16 Bit Mono Class that inherits from header
 * Made by James Kolby
 */

class Mono16Bit : public header, public metadataIO {
public:
	waveHeader fileHeader;
	
	/**
 	* This is the default constructor.
 	*/
	Mono16Bit();
	
	/**
 	* This is the default destructor.
 	*/
	~Mono16Bit();
	
	/**
	 * This function reads audio data from a given fstream object.
	 * @param *file - The ifstream object of the file to be read.
	 */
	short* readAudio(std::ifstream *file);
	
	/**
	 * This function writes audio data to a given fstream object.
	 * @param *file - The ifstream object of the file to be written to.
	 * @param *buffer - The short array of audio data.
	 */
	void writeAudio(std::ofstream *file, short *buffer);
};

#endif //SIXTEEN_BIT_MONO_H
