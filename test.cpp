#include <iostream>
#include <fstream>
#include <string>
#include "8_bit_mono.h"
#include "header.h"

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
	//std::cout << "buffer in test " << buffer << std::endl;
	//delete buffer;
	file.close();
	
	
	// write file
	std::ofstream outfile ("waves/outfile.wav", std::ios::binary | std::ios::out);
	
	test.writeHeader(&outfile);
	test.writeAudio(&outfile, buffer);
	file.close();
}
