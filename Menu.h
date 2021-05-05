#pragma once

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>

#include "echo.h"
#include "noise_gate.h"
#include "normalizer.h"
#include "header.h"

/**
 * This is the template Menu Class that handles the Graphical User Interface
 * Made by Jazzel Radaza
 */


template <class T, class U, class L, class R>
class Menu {

private:
	T wavFile;
	U buffer;
	L bufferL;
	R bufferR;
	bool processDone = false;

	std::string name;
	std::string user_processes;

public:
	/**
	* This is the constructor of the Menu Class
	* @param *newWavFile - This is a templetized parameter. It is the audio wave file that we obtain from reading in the sound files
	* @param newName - contains the name of the audio file
	* @param newBuffer - This is a templetized parameter. This holds the buffer of the wav file
	*/
	Menu(T *newWavFile, std::string newName, U newBuffer);

	/**
	* This is the constructor of the Menu Class
	* @param *newWavFile - This is a templetized parameter. It is the audio wave file that we obtain from reading in the sound files
	* @param newName - contains the name of the audio file
	* @param newBufferL - This is a templetized parameter. This holds the left buffer of the stereo wav file
	* @param newBufferL - This is a templetized parameter. This holds the right buffer of the stereo wav file
	*/
	Menu(T *newWavFile, std::string newName, L newBufferL, R newBufferR);

	/**
	* This function delegates which processors to use depending on the user's choice
	*/

	void processFile();

	/**
	* This function handles the echo processing of different wav files
	*/
	void echoProcessor();

	/**
	* This function handles the noise gate processing of different wav files
	*/
	void noise_gateProcessor();

	/**
	* This function handles the normalizer processing of different wav files
	*/
	void normalizerProcessor();

	/**
	* This function returns the status of processDone when user is done with processing
	*/
	bool returnProcessStatus();

};

template <class T, class U, class L, class R>
bool Menu<T, U, L, R>::returnProcessStatus() {
	return processDone;

};

template <class T, class U, class L, class R>
void Menu<T, U, L, R>::echoProcessor() {
	if (name == "8-bit mono wav file" || name == "16-bit mono wav file") {
		Processor *processorEcho = new Echo(15);
		processorEcho-> processMono(wavFile.fileHeader.data_bytes, buffer);
		std::cout << "Your " << name << " has been successfully processed through the Echo processor" << std::endl;
	}

	if (name == "8-bit stereo wav file" || name == "16-bit stereo wav file") {
		Processor *processorEcho = new Echo(15);
		processorEcho -> processStereo(wavFile.fileHeader.data_bytes, bufferL, bufferR);
		std::cout << "Your " << name << " has been successfully processed through the Echo processor" << std::endl;
	}

};


template <class T, class U, class L, class R>
void Menu<T, U, L, R>::noise_gateProcessor() {
	if (name == "8-bit mono wav file" || name == "16-bit mono wav file") {
		Processor *processorEcho = new NoiseGate(0.05);
		processorEcho-> processMono(wavFile.fileHeader.data_bytes, buffer);
		std::cout << "Your " << name << " has been successfully processed through the Noise Gate processor" << std::endl;
	}

	if (name == "8-bit stereo wav file" || name == "16-bit stereo wav file") {
		Processor *processorEcho = new NoiseGate(0.05);
		processorEcho -> processStereo(wavFile.fileHeader.data_bytes, bufferL, bufferR);
		std::cout << "Your " << name << " has been successfully processed through the Noise Gate processor" << std::endl;
	}

};


template <class T, class U, class L, class R>
void Menu<T, U, L, R>::normalizerProcessor() {
	if (name == "8-bit mono wav file" || name == "16-bit mono wav file") {
		Processor *processorEcho = new Normalizer();
		processorEcho-> processMono(wavFile.fileHeader.data_bytes, buffer);
		std::cout << "Your " << name << " has been successfully processed through the Normalizer processor" << std::endl;
	}

	if (name == "8-bit stereo wav file" || name == "16-bit stereo wav file") {
		Processor *processorEcho = new Normalizer();
		processorEcho -> processStereo(wavFile.fileHeader.data_bytes, bufferL, bufferR);
		std::cout << "Your " << name << " has been successfully processed through the Normalizer processor" << std::endl;
	}
};


template <class T, class U, class L, class R>
void Menu<T, U, L, R>::processFile() {
	std::cout << "How would you like to process your audio file?" << std::endl;
	std::cout << "(Enter the number in order separated by spaces. Example: '1 2 3')" << std::endl;

	std::cout << "[1] Echo Processor" << std::endl;
	std::cout << "[2] Noise Gate Processor" << std::endl;
	std::cout << "[3] Normalizer Processor" << std::endl;

	std::cout << "Enter processes: ";
	std::cin.ignore();
	std::getline(std::cin, user_processes);

	std::istringstream is( user_processes );

	std::vector<int> v;
	int x;

	while ( is >> x ) v.push_back( x );

	std::string processes = "You have chosen the following processors: \n";

	for (int x : v) {
		if (x == 1)
			processes += "- Echo Processor \n";
		if (x == 2)
			processes += "- Noise Gate Processor \n";
		if (x == 3)
			processes += "- Normalizer Processor \n";
	}

	std::cout << processes << std::endl;

	for (int x : v) {
		if (x == 1)
			echoProcessor();
		if (x == 2)
			noise_gateProcessor();
		if (x == 3)
			normalizerProcessor();
	}
	// prompt the user to write and save the file

	std::cout << "Would you like to process more audio files?" << std::endl;
	std::cout << "[1] Yes" << std::endl;
	std::cout << "[0] Exit program" << std::endl;


	int choice;
	std::cout << "Enter choice: "; std::cin >> choice;
	if(choice==0)
		processDone=true;

};



template <class T, class U, class L, class R>
Menu<T, U, L, R>::Menu(T *newWavFile, std::string newName, U newBuffer) : wavFile(*newWavFile), name(newName), buffer(newBuffer) {
	std::cout << "You have chosen to work with the " << name << std::endl;
	std::cout << "What action would you like to take? (Enter the appropriate number)" << std::endl;

	std::cout << "[1] Modify Metadata" << std::endl;
	std::cout << "[2] Process Files" << std::endl;
	std::cout << "[3] Choose another audio file" << std::endl;

	int choice = 0;
	std::cout << "Enter choice: "; std::cin >> choice;
	system("clear");

	if (choice == 2) {
		processFile();
	}

}


template <class T, class U, class L, class R>
Menu<T, U, L, R>::Menu(T *newWavFile, std::string newName, L newBufferL, R newBufferR) : wavFile(*newWavFile), name(newName), bufferL(newBufferL), bufferR(newBufferR) {
	std::cout << "You have chosen to work with the " << name << std::endl;
	std::cout << "What action would you like to take? (Enter the appropriate number)" << std::endl;

	std::cout << "[1] Modify Metadata" << std::endl;
	std::cout << "[2] Process Files" << std::endl;
	std::cout << "[3] Choose another audio file" << std::endl;

	int choice = 0;
	std::cout << "Enter choice: "; std::cin >> choice;
	system("clear");

	if (choice == 2) {
		processFile();
	}

}