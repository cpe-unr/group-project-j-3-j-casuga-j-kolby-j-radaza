#include <fstream>
#include <iostream>
#include "WaveHeader.h"

waveHeader waveHeader::readHeader(const std::string &fileName) {
	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	waveHeader fileHeader;
	
	if (file.is_open()) {
		file.read((char *) &fileHeader, sizeof(wav_header));
		
		unsigned char* buffer = new unsigned char[fileHeader.data_bytes];
		
		file.read((char *) buffer, fileHeader.data_bytes);
		file.close();
	}
	
	return fileHeader;
}
