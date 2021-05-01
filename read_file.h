#ifndef READ_FILE_H
#define READ_FILE_H
#include "wave_header.h"

class readFile : public waveHeader {
public:
	readFile ();
	~readFile ();
	waveHeader fileHeader;
	
	//int getFileSize(std::ifstream file);
	void readHeader(std::ifstream file);
};

#endif
