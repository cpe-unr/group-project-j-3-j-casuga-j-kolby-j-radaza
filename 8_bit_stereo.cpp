#include <iostream>
#include "8_bit_stereo.h"

Stereo8Bit::Stereo8Bit () {}
Stereo8Bit::~Stereo8Bit () {}

void Stereo8Bit::readAudio(std::ifstream *file, unsigned char *bufferL, unsigned char *bufferR) {
	unsigned char *L = new unsigned char;
	unsigned char *R = new unsigned char;
	
	if (file->is_open()) {
		//std::cout << "size " << fileHeader.num_channels << std::endl;
		for (int i=0; i < fileHeader.data_bytes/2; i++) {
			if (i%2==0) {
				file->read((char *) L, 1);
				bufferL[i] = *L;
				//std::cout << "even" << std::endl;
			} else {
				file->read((char *) R, 1);
				bufferR[i] = *R;
				//std::cout << "odd" << std::endl;
			}
			
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
		for (int i=0; i < fileHeader.data_bytes/2; i++) {
			
			//short test = ;
			char Lchar = (char) bufferL[i];
			char Rchar = (char) bufferR[i];
			
			file->write(&Lchar, 1);
			file->write(&Rchar, 1);
			//file << Lchar << Rchar;
		}
	} else {
		std::cout << "Failed to write to file." << std::endl;
	}
}

