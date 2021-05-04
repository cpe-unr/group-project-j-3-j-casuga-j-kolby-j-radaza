#include <fstream>
#include <iostream>
#include "wave_header.h"
#include "header.h"

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
		/*
		for(int i = 0; i < sizeof(fileHeader); i++) {
			file->write((char *)fileHeader[i], sizeof(fileHeader));
		}
		*/
	} else {
		std::cout << "Cannot write file header" << std::endl;
	}
	
	// for testing purposes
	std::string fileName = "waves/testfile.wav";
	std::ofstream testfile (fileName, std::ios::binary | std::ios::out);
	
	if (testfile.is_open()) {
		testfile.write((char *)&fileHeader, sizeof(fileHeader));
		/*
		for(int i = 0; i < sizeof(fileHeader); i++) {
			testfile->write((char *)fileHeader[i], sizeof(fileHeader));
		}
		*/
	} else {
		std::cout << "Cannot write file header" << std::endl;
	}
	
	testfile.close();
}
