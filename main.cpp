/** @file */
#include <iostream>
#include <fstream>
#include <string>



#include "echo.h"
#include "noise_gate.h"
#include "normalizer.h"
#include "Menu.h"

#include "header.h"

#include "8_bit_mono.h"
#include "8_bit_stereo.h"
#include "16_bit_mono.h"
#include "16_bit_stereo.h"
#include "csv.h"
void fn() {

}


int main() {

	//READING OF WAV FILES


	/**
	*	This reads in the 8-bit mono wav file
	*/
	std::string mono_8_name = "8-bit mono wav file";
	std::string mono_8_fileName = "waves/yes-8-bit-mono.wav";
	std::ifstream mono_8_origin (mono_8_fileName, std::ios::binary | std::ios::in);

	if (!mono_8_origin.is_open())
		std::cout << "Failed to open file in main" << std::endl;

	Mono8Bit mono_8_wavFile;
	mono_8_wavFile.readHeader(&mono_8_origin);
	unsigned char*  mono_8_buffer = mono_8_wavFile.readAudio(&mono_8_origin);
	mono_8_origin.close();





	/**
	*	This reads in the 8-bit stereo wav file
	*/
	std::string stereo_8_name = "8-bit stereo wav file";
	std::string stereo_8_fileName = "waves/yes-8-bit-stereo.wav";
	std::ifstream stereo_8_origin (stereo_8_fileName, std::ios::binary | std::ios::in);

	if (!stereo_8_origin.is_open())
		std::cout << "Failed to open file in main" << std::endl;

	Stereo8Bit stereo_8_wavFile;
	stereo_8_wavFile.readHeader(&stereo_8_origin);
	unsigned char *stereo_8_buffer_L = new unsigned char[stereo_8_wavFile.fileHeader.data_bytes];
	unsigned char *stereo_8_buffer_R = new unsigned char[stereo_8_wavFile.fileHeader.data_bytes];

	stereo_8_wavFile.readAudio(&stereo_8_origin, stereo_8_buffer_L, stereo_8_buffer_R);

	stereo_8_origin.close();


	/**
	*	This reads in the 16-bit mono wav file
	*/
	std::string mono_16_name = "16-bit mono wav file";
	std::string mono_16_fileName = "waves/yes-16-bit-mono.wav";
	std::ifstream mono_16_origin (mono_16_fileName, std::ios::binary | std::ios::in);

	if (!mono_16_origin.is_open())
		std::cout << "Failed to open file in main" << std::endl;

	Mono16Bit mono_16_wavFile;
	mono_16_wavFile.readHeader(&mono_16_origin);
	short *mono_16_buffer = mono_16_wavFile.readAudio(&mono_16_origin);
	mono_16_origin.close();


	/**
	*	This reads in the 16-bit stereo wav file
	*/
	std::string stereo_16_name = "16-bit stereo wav file";
	std::string stereo_16_fileName = "waves/yes-16-bit-stereo.wav";
	std::ifstream stereo_16_origin (stereo_16_fileName, std::ios::binary | std::ios::in);

	if (!stereo_16_origin.is_open())
		std::cout << "Failed to open file in main" << std::endl;

	Stereo16Bit stereo_16_wavFile;
	stereo_16_wavFile.readHeader(&stereo_16_origin);

	short *stereo_16_buffer_L = new short[stereo_16_wavFile.fileHeader.data_bytes];
	short *stereo_16_buffer_R = new short[stereo_16_wavFile.fileHeader.data_bytes];

	stereo_16_origin.close();
	


	int choice = 0;

	do {
		std::cout << " ----- Welcome to the Audio File Management System ----- " << std::endl;
		std::cout << " Which file are we working with today? (Input the number) " << std::endl;

		std::cout << "[1] 8-bit mono" << std::endl;
		std::cout << "[2] 8-bit stereo" << std::endl;
		std::cout << "[3] 16-bit mono" << std::endl;
		std::cout << "[4] 16-bit stereo" << std::endl;
		std::cout << "[0] Exit program" << std::endl;



		std::cout << "Enter choice: "; std::cin >> choice;
		system("clear");

		switch (choice) {
		case 0:
			std::cout << "Thank you for using our program. Till we meet again!" << std::endl;
			break;

		// 8-bit MONO
		case 1:{
			Menu<Mono8Bit,unsigned char*, unsigned char*, unsigned char*> menu(&mono_8_wavFile,mono_8_name, mono_8_buffer);
			
			int x1;
			std::cout << "Would you like to make a CSV file?" << std::endl << "[0] No" << std::endl << "[1] Yes" << std::endl;
			std::cin >> x1;
			if(x1 == 1){
				CSV csv1;
				std::string file1;
				std::cout << "CSV File name ending with .CSV: "; std::cin >> file1;
				metadataIO io1;
				csv1.writeCSV(file1, &mono_8_origin, mono_8_wavFile, io1);
			}
			else{
			}
			break;
		}

		case 2:{
			Menu<Stereo8Bit,unsigned char*, unsigned char*, unsigned char*> menu(&stereo_8_wavFile,stereo_8_name, stereo_8_buffer_L, stereo_8_buffer_R);

			int x2;
			std::cout << "Would you like to make a CSV file?" << std::endl << "[0] No" << std::endl << "[1] Yes" << std::endl;
			std::cin >> x2;
			if(x2 == 1){
				CSV csv2;
				std::string file2;
				std::cout << "CSV File name ending with .CSV: "; std::cin >> file2;
				metadataIO io2;
				csv2.writeCSV(file2, &stereo_8_origin, stereo_8_wavFile, io2);
			}
			else{
			}
			break;
		}
		case 3:{
			Menu<Mono16Bit,short*, short*, short*> menu(&mono_16_wavFile,mono_16_name, mono_16_buffer);

			int x3;
			std::cout << "Would you like to make a CSV file?" << std::endl << "[0] No" << std::endl << "[1] Yes" << std::endl;
			std::cin >> x3;
			if(x3 == 1){
				CSV csv3;
				std::string file3;
				std::cout << "CSV File name ending with .CSV: "; std::cin >> file3;
				metadataIO io3;
				csv3.writeCSV(file3, &mono_16_origin, mono_16_wavFile, io3);
			}
			else{
			}
			break;
		}

		case 4:{
			  Menu<Stereo16Bit,short*, short*, short*> menu(&stereo_16_wavFile,stereo_16_name, stereo_16_buffer_L, stereo_16_buffer_R);

			int x4;
			std::cout << "Would you like to make a CSV file?" << std::endl << "[0] No" << std::endl << "[1] Yes" << std::endl;
			std::cin >> x4;
			if(x4 == 1){
				CSV csv4;
				std::string file4;
				std::cout << "CSV File name ending with .CSV: "; std::cin >> file4;
				metadataIO io4;
				csv4.writeCSV(file4, &stereo_16_origin, stereo_16_wavFile, io4);
			}
			else{
			}
			break;
		}

		default:{
			std::cout << "Please enter a valid option" << std::endl;
			break;
		}

	    }
	} while (choice != 0); 
	return 0;
}
