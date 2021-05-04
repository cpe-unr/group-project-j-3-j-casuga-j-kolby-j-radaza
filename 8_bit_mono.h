#ifndef EIGHT_BIT_MONO
#define EIGHT_BIT_MONO
#include <fstream>
#include "header.h"
#include "metadata_io.h"
/**
 * This is the 8 Bit Mono Class that inherits from header
 * Made by James Kolby
 */
//public metadataIO,
class Mono8Bit :  public header {
public:
	/**
 	* This is the default constructor.
 	*/
	Mono8Bit();
	
	/**
 	* This is the default destructor.
 	*/
	~Mono8Bit();
	
	/**
	 * This function reads audio data from a given fstream object.
	 * @param *file - The ifstream object of the file to be read.
	 */
	unsigned char* readAudio(std::ifstream *file);
	
	/**
	 * This function writes audio data to a given fstream object.
	 * @param *file - The ifstream object of the file to be written to.
	 * @param *buffer - The unsigned char* array of audio data.
	 */
	void writeAudio(std::ofstream *file, unsigned char* buffer);

};

#endif //EIGHT_BIT_MONO
