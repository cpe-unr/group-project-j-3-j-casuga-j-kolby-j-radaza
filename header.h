#ifndef READ_FILE_H
#define READ_FILE_H
#include <fstream>
#include "wave_header.h"
/**
 * This is the header class that contains actions regarding the header of any wave file.
 * Made by James Kolby
 */

class header : public waveHeader {
public:
	waveHeader fileHeader;
	
	/**
 	* This is the default constructor.
 	*/
	header ();
	
	/**
 	* This is the default destructor.
 	*/
	~header ();
	
	/**
	 * This function reads the file header from a given fstream object.
	 * @param *file - The ifstream object of the file to be read.
	 */
	void readHeader(std::ifstream *file);
	
	/**
	 * This function writes the file header to a given fstream object.
	 * @param *file - The ifstream object of the file to be written to.
	 */
	void writeHeader(std::ofstream *file);
};

#endif //READ_FILE_H
