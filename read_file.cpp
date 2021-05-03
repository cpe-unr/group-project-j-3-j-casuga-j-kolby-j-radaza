#include <fstream>
#include <iostream>
#include "wave_header.h"
#include "read_file.h"

readFile::readFile () {}
readFile::~readFile () {}

void readFile::readHeader(std::ifstream *file) {
	if (file->is_open()) {
		file->read((char *) &fileHeader, sizeof(fileHeader));
	} else {
		std::cout << "Failed to read header from file" <<std::endl;
	}
}
