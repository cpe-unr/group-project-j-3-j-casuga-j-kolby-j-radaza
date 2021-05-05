/** @file */
/**
* This is the main file that is responsible for handling all of the processes of the Audio File Management System
* Implemented by Jazzel Radaza
*/
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

bool processStatus = false;

void fn() {

}

void continueProcess() {
	std::cout << "Would you like to process more audio files?" << std::endl;
	std::cout << "[1] Yes" << std::endl;
	std::cout << "[0] No. Exit program" << std::endl;


	int choice;
	std::cout << "Enter choice: "; std::cin >> choice;
	if (choice == 0)
		processStatus = true;

}

int main() {

	std::string fileName_8_mono = "yes-8-bit-mono";
	std::string fileName_8_stereo = "yes-8-bit-stereo";
	std::string fileName_16_mono = "yes-16-bit-mono";
	std::string fileName_16_stereo = "yes-16-bit-stereo";

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


	std::cout << " ----- Welcome to the Audio File Management System ----- " << std::endl;

	int choice = 0;


	do {
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
			processStatus = false;
			break;

		case 1: {
			Menu<Mono8Bit, unsigned char*, unsigned char*, unsigned char*> menu(&mono_8_wavFile, mono_8_name, mono_8_buffer);
			std::cout << "\n \nCongratulations on successfully processing your audio files.It is now time to save our changes." << std::endl;
			std::string newFileName;

			do {
				std::cout << "\nPlease enter a file name for your new audio file: ";
				std::getline(std::cin, newFileName);
				if ((newFileName == fileName_8_mono) || (newFileName == fileName_8_stereo) || (newFileName == fileName_16_mono) || (newFileName == fileName_16_stereo))
					std::cout << "Please choose a different file name" << std::endl;
				else {
					std::string fileName = "waves/" + newFileName + ".wav";
					std::ofstream outfile (fileName, std::ios::binary | std::ios::out);
					mono_8_wavFile.writeHeader(&outfile);
					mono_8_wavFile.writeAudio(&outfile, mono_8_buffer);
					mono_8_origin.close();
				}

			} while ((newFileName == fileName_8_mono) || (newFileName == fileName_8_stereo) || (newFileName == fileName_16_mono) || (newFileName == fileName_16_stereo));
			continueProcess();
			break;
		}

		case 2: {
			Menu<Stereo8Bit, unsigned char*, unsigned char*, unsigned char*> menu(&stereo_8_wavFile, stereo_8_name, stereo_8_buffer_L, stereo_8_buffer_R);
			std::cout << "\n \nCongratulations on successfully processing your audio files.It is now time to save our changes." << std::endl;
			std::string newFileName;

			do {
				std::cout << "\nPlease enter a file name for your new audio file: ";
				std::getline(std::cin, newFileName);
				if ((newFileName == fileName_8_mono) || (newFileName == fileName_8_stereo) || (newFileName == fileName_16_mono) || (newFileName == fileName_16_stereo))
					std::cout << "Please choose a different file name" << std::endl;
				else {
					std::string fileName = "waves/" + newFileName + ".wav";
					std::ofstream outfile (fileName, std::ios::binary | std::ios::out);
					stereo_8_wavFile.writeHeader(&outfile);
					stereo_8_wavFile.writeAudio(&outfile, stereo_8_buffer_L, stereo_8_buffer_R);
					stereo_8_origin.close();
				
				}

			} while ((newFileName == fileName_8_mono) || (newFileName == fileName_8_stereo) || (newFileName == fileName_16_mono) || (newFileName == fileName_16_stereo));
			continueProcess();
			break;
		}


		case 3: {
			Menu<Mono16Bit, short*, short*, short*> menu(&mono_16_wavFile, mono_16_name, mono_16_buffer);
			std::cout << "\n \nCongratulations on successfully processing your audio files.It is now time to save our changes." << std::endl;
			std::string newFileName;

			do {
				std::cout << "\nPlease enter a file name for your new audio file: ";
				std::getline(std::cin, newFileName);
				if ((newFileName == fileName_8_mono) || (newFileName == fileName_8_stereo) || (newFileName == fileName_16_mono) || (newFileName == fileName_16_stereo))
					std::cout << "Please choose a different file name" << std::endl;
				else {
					std::string fileName = "waves/" + newFileName + ".wav";
					std::ofstream outfile (fileName, std::ios::binary | std::ios::out);
					mono_16_wavFile.writeHeader(&outfile);
					mono_16_wavFile.writeAudio(&outfile, mono_16_buffer);
					mono_16_origin.close();
				}

			} while ((newFileName == fileName_8_mono) || (newFileName == fileName_8_stereo) || (newFileName == fileName_16_mono) || (newFileName == fileName_16_stereo));
			continueProcess();
			break;
		}

		case 4: {
			Menu<Stereo16Bit, short*, short*, short*> menu(&stereo_16_wavFile, stereo_16_name, stereo_16_buffer_L, stereo_16_buffer_R);
			std::cout << "\n \nCongratulations on successfully processing your audio files.It is now time to save our changes." << std::endl;
			std::string newFileName;

			do {
				std::cout << "\nPlease enter a file name for your new audio file: ";
				std::getline(std::cin, newFileName);
				if ((newFileName == fileName_8_mono) || (newFileName == fileName_8_stereo) || (newFileName == fileName_16_mono) || (newFileName == fileName_16_stereo))
					std::cout << "Please choose a different file name" << std::endl;
				else {
					std::string fileName = "waves/" + newFileName + ".wav";
					std::ofstream outfile (fileName, std::ios::binary | std::ios::out);
					stereo_16_wavFile.writeHeader(&outfile);
					stereo_16_wavFile.writeAudio(&outfile, stereo_16_buffer_L, stereo_16_buffer_R);
					stereo_16_origin.close();
				
				}

			} while ((newFileName == fileName_8_mono) || (newFileName == fileName_8_stereo) || (newFileName == fileName_16_mono) || (newFileName == fileName_16_stereo));
			continueProcess();
			break;
		}

		default:
			std::cout << "Please enter a valid option" << std::endl;
			break;
		}


	} while (processStatus == false); // change this to when the bool flag for process done is over.










	return 0;
}
