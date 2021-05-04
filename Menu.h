#pragma once

#include <iostream>

#include "echo.h"
#include "noise_gate.h"
#include "normalizer.h"

template <class T>
class Menu {

private:
	T wavFile;
	std::string name;
	//T number;

public:
	Menu();
	Menu(T *newWavFile, std::string newName);
	//Menu(T numberS);

};


/**
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
Menu<T>::Menu(T *newWavFile,std::string newName) : wavFile(*newWavFile), name(newName) {
		std::cout << "You have chosen to work with the "<< name << std::endl;
		//wavFile.printTest();
		
}
