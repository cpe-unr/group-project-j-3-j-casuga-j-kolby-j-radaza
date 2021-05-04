#include <fstream>
#include <iostream>
#include "wave_header.h"
#include "header.h"


// header implementation
header::header () {}
header::~header () {}

void header::readHeader(std::ifstream *file) {
/*
	if (file->is_open()) {
		//for (int i = 0; i < (sizeof(fileHeader)/4); i++) {
			file->read(fileHeader.riff_header, 4);
			char test[1024];
			file->read(test, 1024);
			//std::cout << "test " << fileHeader.riff_header << " end\n" << std::endl;
		//}
	} else {
		std::cout << "Cannot write file header" << std::endl;
	}
*/
	if (file->is_open()) {
		file->read((char *) &fileHeader, sizeof(fileHeader));
	} else {
		std::cout << "Failed to read header from file" <<std::endl;
	}
	
}

void header::writeHeader(std::ofstream *file) {
	if (file->is_open()) {
		file->write((char *)&fileHeader, sizeof(fileHeader));
	} else {
		std::cout << "Cannot write file header" << std::endl;
	}
}


// metadata implemendation
metadataIO::metadataIO () {}
metadataIO::~metadataIO () {}

void metadataIO::readMetadata(std::ifstream *file) {
	if (file->is_open()) {
		file->read((char *) &Metadata, sizeof(Metadata));
		//std::cout << "in the meta " << Metadata.inam << " end" << std::endl;
	} else {
		std::cout << "Failed to read metadata from file" <<std::endl;
	}
}

void metadataIO::writeMetadata(std::ofstream *file) {
	if (file->is_open()) {
		file->write((char *)&Metadata, sizeof(Metadata));
	} else {
		std::cout << "Cannot write metadata to file" << std::endl;
	}
}
