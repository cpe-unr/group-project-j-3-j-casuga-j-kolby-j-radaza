#include <fstream>
#include "8_bit_mono.h"

Mono8Bit::Mono8Bit () {}
Mono8Bit::~Mono8Bit () {}

unsigned char* Mono8Bit::readAudio(std::ifstream file) {
	unsigned char* buffer[data_bytes];
	
	if (file.is_open()) {
		file.read((char *) buffer, data_bytes);
//		file.read((char *) buffer, wave_header.data_bytes);
	}
	
	return *buffer;  // gonna need a delete[] buffer later
}

