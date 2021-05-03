#ifndef READ_FILE_H
#define READ_FILE_H
#include <fstream>
#include "wave_header.h"

class header : public waveHeader {
public:
	header ();
	~header ();
	waveHeader fileHeader;
	
	//int getFileSize(std::ifstream file);
	void readHeader(std::ifstream *file);
	void writeHeader(std::ofstream *file);
};

#endif
