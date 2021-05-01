#include <fstream>
#include <iostream>
#include "wave_header.h"
#include "read_file.h"

readFile::readFile () {}
readFile::~readFile () {}
/*
int readFile::getFileSize(std::ifstream file) {
    int fileSize = 0;
    fseek(file, 0, SEEK_END);

    fileSize = ftell(file);

    fseek(file, 0, SEEK_SET);
    return fileSize;
}
*/
void readFile::readHeader(std::ifstream file) {
	waveHeader wave_header;
	
	if (file.is_open()) {
		file.read((char *) &wave_header, sizeof(waveHeader));
		
		unsigned char* buffer = new unsigned char[wave_header.data_bytes];
		
		file.read((char *) buffer, wave_header.data_bytes);
	}
	
	fileHeader = wave_header;
}
