#include <fstream>
#include <iostream>
#include "16_bit_mono.h"

Mono16Bit::Mono16Bit () {}
Mono16Bit::~Mono16Bit () {}

short* Mono16Bit::readAudio(std::ifstream *file) {
	short *buffer = new short[fileHeader.data_bytes];
	
	if (file->is_open()) {
		//std::cout << "data bytes in 8 bit mono " << fileHeader.data_bytes << std::endl;
		file->read((char *) buffer, fileHeader.data_bytes);
	} else {
		std::cout << "Failed to read audio data from file." << std::endl;
	}
	
	return buffer;
}

void Mono16Bit::writeAudio(std::ofstream *file, short *buffer) {
	if (file->is_open()) {
		//file << buffer;
		file->write((char *) buffer, fileHeader.data_bytes);
	} else {
		std::cout << "Failed to write to file." << std::endl;
	}
}

