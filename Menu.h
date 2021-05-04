#pragma once

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>

#include "echo.h"
#include "noise_gate.h"
#include "normalizer.h"

template <class T>
class Menu {

private:
	T wavFile;
	std::string name;
	std::string user_processes;
	//T number;

public:
	//Menu();
	Menu(T *newWavFile, std::string newName);
	void processFile();

	void edd() {
		std::cout << "add func" << std::endl;

	};



};

template <class T>
void Menu<T>::processFile() {
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
	for(int x:v){
		if(x == 1)
			std::cout << "Chosen Echo Processor" << std::endl;
		if(x==2)
			std::cout << "Chosen Noise Gate Processor" << std::endl;
		if(x==3)
			std::cout << "Chosen Normalizer Processor" << std::endl;

	}
	/**
	for ( int x : v) std::cout << x << ' ';
	std::cout << std::endl;
	**/
	std::cout << user_processes << std::endl;



};
/////////////////////////////




/**
void edd() {
	std::cout << "edd func" << std::endl;

};

template<typename T>
Menu<T>::Menu(){
    number = 0;
}

template <class T>
Menu<T>::Menu(T numberS) : number(numberS) {
	std::cout << "PRINTING ARRAY --------------->"<< number[32] << std::endl;
}


**/


template <class T>
Menu<T>::Menu(T *newWavFile, std::string newName) : wavFile(*newWavFile), name(newName) {
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