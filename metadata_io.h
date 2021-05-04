#ifndef META_IO_H
#define META_IO_H
#include <fstream>
#include "metadata.h"
/**
 * This is the metadataIO class that contains methods for writing and reading metadata
 * Made by James Kolby
 */

class metadataIO : public metadata {
public:
	metadata Metadata;
	
	/**
 	* This is the default constructor.
 	*/
	metadataIO ();
	
	/**
 	* This is the default destructor.
 	*/
	~metadataIO ();
	
	/**
	 * This function reads the file metadata from a given fstream object.
	 * @param *file - The ifstream object of the file to be read.
	 */
	void readMetadata(std::ifstream *file);
	
	/**
	 * This function writes the file metadata to a given fstream object.
	 * @param *file - The ifstream object of the file to be written to.
	 */
	void writeMetadata(std::ofstream *file);
};

#endif //READ_FILE_H
