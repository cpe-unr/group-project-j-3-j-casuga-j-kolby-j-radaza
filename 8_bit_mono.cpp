#include <fstream>
#include <iostream>
#include "8_bit_mono.h"

Mono8Bit::Mono8Bit () {}
Mono8Bit::~Mono8Bit () {}

unsigned char* Mono8Bit::readAudio(std::ifstream *file) {
	unsigned char *buffer = new unsigned char[fileHeader.data_bytes];
	
	if (file->is_open()) {
		file->read((char *) buffer, fileHeader.data_bytes);
	} else {
		std::cout << "Failed to read audio data from file." << std::endl;
	}
	
	return buffer;
}

void Mono8Bit::writeAudio(std::ofstream *file, unsigned char *buffer) {
	if (file->is_open()) {
		file->write((char *)buffer, fileHeader.data_bytes);
	} else {
		std::cout << "Failed to write to file." << std::endl;
	}
}
