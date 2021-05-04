#include <fstream>
#include <iostream>
#include "wave_header.h"
#include "header.h"


// header implementation
header::header () {}
header::~header () {}

void header::readHeader(std::ifstream *file) {
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
	if (file->is_open() && 0) {
		char * tag = new char [4];
		int bytesRead = 2;
		
		do {
			bytesRead ++;
			file->read((char *) tag, 4);
			std::string s;
			s.push_back(*tag);
			if (s.find("I") != std::string::npos) {
				std::cout << "------------" << std::endl;
				break;
			}
			if (bytesRead == 2000000) {
				break;
			}
		} while (tag != NULL);
		delete tag;
		
		file->read((char *) &Metadata, sizeof(Metadata));
		std::cout << "in the meta " << Metadata.inam << " end" << std::endl;
		
	} else {
		if (file->is_open()) {
			file->read((char *) &Metadata, sizeof(Metadata));
			//std::cout << "in the meta " << Metadata.inam << " end" << std::endl;
		} else {
			std::cout << "Failed to read metadata from file" <<std::endl;
		}
	
		std::cout << "Failed to read metadata from file" <<std::endl;
	}
}

void metadataIO::writeMetadata(std::ofstream *file) {
	if (file->is_open()) {
		//file->write((char *)&Metadata, sizeof(Metadata));
	} else {
		std::cout << "Cannot write metadata to file" << std::endl;
	}
}
