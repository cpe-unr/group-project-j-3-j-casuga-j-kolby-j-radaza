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
//NOTE: short is used for 16 bit unsigned char is used for 8 bit


/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}

int main() {
	std::string chosenWavFile;

	// Read in the wav files
	
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

	
    std::cout << " ----- Welcome to the Audio File Management System ----- " << std::endl;
	std::cout << " Which file are we working with today? (Choose the number corresponding) " << std::endl;

	std::cout << "[1] 8-bit mono" << std::endl;
	std::cout << "[2] 8-bit stereo" << std::endl;
	std::cout << "[3] 16-bit mono" << std::endl;
	std::cout << "[4] 26-bit stereo" << std::endl;
	
	int choice = 0;

	std::cout << "Enter choice: "; std::cin >> choice;

	
	//Menu menu();









    return 0;
}
