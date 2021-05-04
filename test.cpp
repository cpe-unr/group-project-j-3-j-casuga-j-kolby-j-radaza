#include <iostream>
#include <fstream>
#include <string>
#include "8_bit_mono.h"
#include "8_bit_stereo.h"
#include "16_bit_mono.h"
#include "16_bit_stereo.h"
#include "header.h"

int main() {
// 8 bit mono
	/*
	std::string fileName = "waves/yes-8-bit-mono.wav";
	std::ifstream file (fileName, std::ios::binary | std::ios::in);
	
	if (file.is_open()) {
		//
	} else {
		std::cout << "Failed to open file in main" <<std::endl;
	}
	
	// read file
	Mono8Bit test;
	test.readHeader(&file);
	unsigned char* buffer = test.readAudio(&file);
	//std::cout << "buffer in test " << buffer << std::endl;
	delete buffer;
	std::cout << test.data_bytes << " bytes and channels " << test.num_channels << std::endl;
	file.close();
	
	
	// write file
	std::ofstream outfile ("waves/outfile.wav", std::ios::binary | std::ios::out);
	
	test.writeHeader(&outfile);
	test.writeAudio(&outfile, buffer);
	file.close();
	*/
	
// 8 bit stereo
	/*
	std::string fileName = "waves/yes-8-bit-stereo.wav";
	std::ifstream file (fileName, std::ios::binary | std::ios::in);
	
	if (file.is_open()) {
		std::cout << "Opened File Successfull" << std::endl;
	} else {
		std::cout << "Failed to open file in main" <<std::endl;
	}
	
	// read file
	Stereo8Bit test;
	test.readHeader(&file);
	unsigned char *bufferL = new unsigned char[test.fileHeader.data_bytes];
	unsigned char *bufferR = new unsigned char[test.fileHeader.data_bytes];
	test.readAudio(&file, bufferL, bufferR);
	//std::cout << "test" << std::endl;
	std::cout << "bufferL in test " << bufferL << std::endl;
	//delete buffer;
	file.close();
	
	/*
	// write file
	std::ofstream outfile ("waves/outfile.wav", std::ios::binary | std::ios::out);
	
	test.writeHeader(&outfile);
	test.writeAudio(&outfile, buffer);
	file.close();
	*/


// 16 bit mono
	/*
	std::string fileName = "waves/yes-16-bit-mono.wav";
	std::ifstream file (fileName, std::ios::binary | std::ios::in);
	
	if (file.is_open()) {
		//
	} else {
		std::cout << "Failed to open file in main" <<std::endl;
	}
	
	// read file
	Mono16Bit test;
	test.readHeader(&file);
	short *buffer = test.readAudio(&file);
	std::cout << "buffer in test " << buffer << std::endl;
	delete buffer;
	std::cout << test.data_bytes << " bytes and channels " << test.num_channels << std::endl;
	file.close();
	
	
	// write file
	std::ofstream outfile ("waves/outfile.wav", std::ios::binary | std::ios::out);
	
	test.writeHeader(&outfile);
	test.writeAudio(&outfile, buffer);
	file.close();
	
	*/

// 16 bit stereo
	std::string fileName = "waves/yes-16-bit-stereo.wav";
	std::ifstream file (fileName, std::ios::binary | std::ios::in);
	
	if (file.is_open()) {
		std::cout << "Opened File Successfull" << std::endl;
	} else {
		std::cout << "Failed to open file in main" <<std::endl;
	}
	
	// read header
	Stereo16Bit test;
	test.readHeader(&file);
	std::cout << "riff_header " << test.riff_header << std::endl;
	std::cout << "num_channels " << test.num_channels << std::endl;
	std::cout << "data_header " << test.data_header << std::endl;
	
	// read audio
	short *bufferL = new short[test.fileHeader.data_bytes];
	short *bufferR = new short[test.fileHeader.data_bytes];
	test.readAudio(&file, bufferL, bufferR);
	std::cout << "bufferL in test " << *bufferL << std::endl;
	//std::cout << "bufferR in test " << bufferR << std::endl;
	//std::cout << "data_bytes " << test.data_bytes << " # of channels " << test.num_channels << std::endl;
	file.close();
	
	
	// write file
	std::ofstream outfile ("waves/outfile.wav", std::ios::binary | std::ios::out);
	
	test.writeHeader(&outfile);
	test.writeAudio(&outfile, bufferL, bufferR);

	file.close();
	delete bufferL;
	delete bufferR;
}

