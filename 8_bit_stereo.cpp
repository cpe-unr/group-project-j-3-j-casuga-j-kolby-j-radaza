#include <iostream>
#include "8_bit_stereo.h"

Stereo8Bit::Stereo8Bit () {}
Stereo8Bit::~Stereo8Bit () {}

void Stereo8Bit::readAudio(std::ifstream *file, unsigned char *bufferL, unsigned char *bufferR) {
	unsigned char *L = new unsigned char;
	unsigned char *R = new unsigned char;
	
	if (file->is_open()) {
		std::cout << "size " << fileHeader.num_channels << std::endl;
		for (int i=0; i < fileHeader.data_bytes/2; i++) {
			
			file->read((char *) L, 1);
			file->read((char *) R, 1);
			
			bufferL[2*i-1] = *L;
			bufferR[2*i] = *R;
			
			//std::cout << "Left " << L << bufferL[2*i-1] << std::endl;
			//std::cout << "Right " << R << bufferR[2*i-1] << std::endl;
		}
		delete L;
		delete R;
	} else {
		std::cout << "Failed to read audio data from file." << std::endl;
	}
}


void Stereo8Bit::writeAudio(std::ofstream *file, unsigned char *bufferL, unsigned char *bufferR) {
	if (file->is_open()) {
		file->write((char *)bufferL, (fileHeader.data_bytes/2));
		file->write((char *)bufferL, (fileHeader.data_bytes/2));
	} else {
		std::cout << "Failed to write to file." << std::endl;
	}
}

