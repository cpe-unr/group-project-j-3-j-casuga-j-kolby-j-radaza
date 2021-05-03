#include <iostream>
#include <fstream>
#include <string>
#include "8_bit_mono.h"
#include "read_file.h"

int main() {
	std::string fileName = "waves/yes-8bit-mono.wav";
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
	//std::cout << "buffer size " << buffer << std::endl;
	delete buffer;
	file.close();
	
	// write file
	/*
	std::ofstream &outfile (fileName, std::ios::binary | std::ios::in);
	test.writeAudio(outfile, buffer);
	file.close();
	*/
}
