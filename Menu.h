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


template <class T, class U, class L, class R>
class Menu {

private:
	T wavFile;
	U buffer;
	L bufferL;
	R bufferR;

	std::string name;
	std::string user_processes;
	//T number;

public:
	//Menu();
	Menu(T *newWavFile, std::string newName, U newBuffer);
	Menu(T *newWavFile, std::string newName, L newBufferL, R newBufferR);

	void processFile();

	void echoProcessor();
	void noise_gateProcessor();
	void normalizerProcessor();




};

template <class T, class U, class L, class R>
void Menu<T, U, L, R>::echoProcessor() {
	if (name == "8-bit mono wav file" || name == "16-bit mono wav file") {
		Processor *processorEcho = new Echo(15);
		processorEcho-> processMono(wavFile.fileHeader.data_bytes, buffer);
		std::cout << "SUCCESS ECHO "<< name << std::endl;
	}

	if (name == "8-bit stereo wav file" || name == "16-bit stereo wav file") {
		Processor *processorEcho = new Echo(15);
		processorEcho -> processStereo(wavFile.fileHeader.data_bytes, bufferL, bufferR);
		std::cout << "SUCCESS ECHO "<< name << std::endl;
	}

};

template <class T, class U, class L, class R>
void Menu<T, U, L, R>::noise_gateProcessor() {
	if (name == "8-bit mono wav file" || name == "16-bit mono wav file") {
		Processor *processorEcho = new NoiseGate(0.05);
		processorEcho-> processMono(wavFile.fileHeader.data_bytes, buffer);
		std::cout << "SUCCESS NOISE GATE "<< name << std::endl;
	}

	if (name == "8-bit stereo wav file" || name == "16-bit stereo wav file") {
		Processor *processorEcho = new NoiseGate(0.05);
		processorEcho -> processStereo(wavFile.fileHeader.data_bytes, bufferL, bufferR);
		std::cout << "SUCCESS NOISE GATE "<< name << std::endl;
	}

};

template <class T, class U, class L, class R>
void Menu<T, U, L, R>::normalizerProcessor() {
	if (name == "8-bit mono wav file" || name == "16-bit mono wav file") {
		Processor *processorEcho = new Normalizer();
		processorEcho-> processMono(wavFile.fileHeader.data_bytes, buffer);
		std::cout << "SUCCESS NORMALIZER "<< name << std::endl;
	}

	if (name == "8-bit stereo wav file" || name == "16-bit stereo wav file") {
		Processor *processorEcho = new Normalizer();
		processorEcho -> processStereo(wavFile.fileHeader.data_bytes, bufferL, bufferR);
		std::cout << "SUCCESS NORMALIZER "<< name << std::endl;
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

	std::string processes = "You have chosen the following processors: ";

	for (int x : v) {
		if (x == 1)
			processes += "Echo Processor,";
		if (x == 2) 
			processes += "Noise Gate Processor,";
		if (x == 3) 
			processes += "Normalizer Processor";
	}

	std::cout << processes << std::endl;

	for (int x : v) {
		if (x == 1) {
			echoProcessor();
			//std::cout << "Chosen Echo Processor" << std::endl;
		}

		if (x == 2) {
			noise_gateProcessor();
			//std::cout << "Chosen Noise Gate Processor" << std::endl;
		}
		if (x == 3) {
			normalizerProcessor();
			//std::cout << "Chosen Normalizer Processor" << std::endl;
		}

	}

	std::cout << user_processes << std::endl;



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

	if (choice == 2) {
		processFile();
	}

}
#include "Menu.cpp"