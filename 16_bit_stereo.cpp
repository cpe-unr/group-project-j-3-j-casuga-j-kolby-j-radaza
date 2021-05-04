#include <fstream>
#include <iostream>
#include "16_bit_stereo.h"

Stereo16Bit::Stereo16Bit () {}
Stereo16Bit::~Stereo16Bit () {}

void Stereo16Bit::readAudio(std::ifstream *file, short *bufferL, short *bufferR) {
	short *L = new short;
	short *R = new short;
	
	if (file->is_open()) {
		for (int i=0; i < fileHeader.data_bytes-1; i++) {
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

void Stereo16Bit::writeAudio(std::ofstream *file, short *bufferL, short *bufferR) {
	if (file->is_open()) {
		for (int i=0; i < fileHeader.data_bytes-1; i++) {
			if (i%2==0) {
				char Lchar = (char) bufferL[i];
				file->write(&Lchar, 1);
			} else {
				char Rchar = (char) bufferR[i];
				file->write(&Rchar, 1);
			}
		}
	} else {
		std::cout << "Failed to write to file." << std::endl;
	}
}

