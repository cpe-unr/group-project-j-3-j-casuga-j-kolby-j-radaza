#include <iostream>
#include <fstream>
#include <string>
#include "8_bit_mono.h"
#include "8_bit_stereo.h"
#include "16_bit_mono.h"
#include "16_bit_stereo.h"
#include "header.h"
#include "csv.h"

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
	
	
	// write file
	std::ofstream outfile ("waves/outfile.wav", std::ios::binary | std::ios::out);
	std::cout << "reading done" << std::endl;
	test.writeHeader(&outfile);
	test.writeAudio(&outfile, bufferL, bufferR);
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
	//delete buffer;
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
		//std::cout << "Opened File Successfull" << std::endl;
	} else {
		std::cout << "Failed to open file in main" <<std::endl;
	}
	
	// read header
	Stereo16Bit test;
	test.readHeader(&file);
	std::cout << "riff " << test.fileHeader.riff_header << " size " << sizeof(test.fileHeader.riff_header) << std::endl;
	
	//std::cout << "riff_header " << test.fileHeader.riff_header << std::endl;
	//std::cout << "num_channels " << test.fileHeader.num_channels << std::endl;
	//std::cout << "data_header " << test.fileHeader.data_header << std::endl;
	
	
	// read audio
	short *bufferL = new short[test.fileHeader.data_bytes];
	short *bufferR = new short[test.fileHeader.data_bytes];
	test.readAudio(&file, bufferL, bufferR);
	//std::cout << "bufferL in test " << bufferL[100] << std::endl;
	//std::cout << "bufferR in test " << bufferR << std::endl;
	//std::cout << "data_bytes " << test.data_bytes << " # of channels " << test.num_channels << std::endl;
	
	// read metadata *note metadata is at the end of the file and should be read last*
	test.readMetadata(&file);
	
	std::cout << "size of metadata " << sizeof(test.inam) << std::endl;
	std::cout << "Metadata " << test.inam  << " end" << std::endl;


	//This format is how to get the CSV file written. In this case the variable files should be the name of the the CSV file with the .CSV at the end. file should be an ifstream variable as shown above this code. Test should be the object that is created by any of the subclasses 8bit 16 bit etc. io is just a new metadataIO object.
	CSV csv;
	std::string files;
	std::cout << "CSV File name: "; std::cin >> files;
	metadataIO io;
	csv.writeCSV(files, &file, test, io);


	file.close();
	
	
	// write file
	
	std::ofstream outfile ("waves/outfile.wav", std::ios::binary | std::ios::out);
	std::cout << "reading done" << std::endl;
	test.writeHeader(&outfile);
	test.writeAudio(&outfile, bufferL, bufferR);
	test.writeMetadata(&outfile);

	file.close();
	delete bufferL;
	delete bufferR;
	/*
	CSV csv1;
	std::string file1;
	std::cout << "CSV File name: "; std::cin >> file1;
	metadataIO io1;
	csv.writeCSV(file1, &mono_8_origin, mono_8_waveFile, io1);

	CSV csv2;
	std::string file2;
	std::cout << "CSV File name: "; std::cin >> file2;
	metadataIO io2;
	csv.writeCSV(file2, &stereo_8_origin, stereo_8_wavFile, io2);

	CSV csv3;
	std::string file3;
	std::cout << "CSV File name: "; std::cin >> file3;
	metadataIO io3;
	csv.writeCSV(file3, &mono_16_origin, mono_16_wavFile, io3);

	CSV csv4;
	std::string file4;
	std::cout << "CSV File name: "; std::cin >> file4;
	metadataIO io4;
	csv.writeCSV(file4, &stereo_16_origin, stereo_16_wavFile, io4);
	*/
}

