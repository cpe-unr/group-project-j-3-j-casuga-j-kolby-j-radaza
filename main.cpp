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
void fn() {

}


int main() {

	//READING OF WAV FILES


	/**
	*	This reads in the 8-bit mono wav file
	*/
	std::string fileName1 = "waves/yes-8bit-mono.wav";
	std::ifstream file1 (fileName1, std::ios::binary | std::ios::in);

	if (!file1.is_open())
		std::cout << "Failed to open file in main" << std::endl;

	Mono8Bit test1;
	test1.readHeader(&file1);
	unsigned char* buffer1 = test1.readAudio(&file1);
	file1.close();


	/**
	*	This reads in the 8-bit stereo wav file
	*/
	std::string fileName2 = "waves/yes-8-bit-stereo.wav";
	std::ifstream file2 (fileName2, std::ios::binary | std::ios::in);

	if (!file2.is_open())
		std::cout << "Failed to open file in main" << std::endl;

	Mono8Bit test2;
	test2.readHeader(&file2);
	unsigned char* buffer2 = test2.readAudio(&file2);
	file2.close();


	/**
	*	This reads in the 16-bit mono wav file
	*/
	std::string fileName3 = "waves/yes-8bit-mono.wav";
	std::ifstream file3 (fileName3, std::ios::binary | std::ios::in);

	if (!file3.is_open())
		std::cout << "Failed to open file in main" << std::endl;

	Mono8Bit test3;
	test3.readHeader(&file3);
	unsigned char* buffer3 = test3.readAudio(&file3);
	file3.close();


	/**
	*	This reads in the 26-bit stereo wav file
	*/
	std::string fileName4 = "waves/yes-8-bit-stereo.wav";
	std::ifstream file4 (fileName4, std::ios::binary | std::ios::in);

	if (!file4.is_open())
		std::cout << "Failed to open file in main" << std::endl;

	Mono8Bit test4;
	test4.readHeader(&file4);
	unsigned char* buffer4 = test4.readAudio(&file4);
	file4.close();

	int choice = 0;

	do {
		std::cout << " ----- Welcome to the Audio File Management System ----- " << std::endl;
		std::cout << " Which file are we working with today? (Input the number) " << std::endl;

		std::cout << "[1] 8-bit mono" << std::endl;
		std::cout << "[2] 8-bit stereo" << std::endl;
		std::cout << "[3] 16-bit mono" << std::endl;
		std::cout << "[4] 26-bit stereo" << std::endl;
		std::cout << "[0] Exit program" << std::endl;



		std::cout << "Enter choice: "; std::cin >> choice;

		switch (choice) {
		case 0:
			std::cout << "Thank you for using our program. Till we meet again!" << std::endl;
			break;

		// 8-bit MONO
		case 1:
			//Menu menu(&buffer1);

			break;



		case 2:
			break;



		case 3:
			break;

		case 4:
			break;

		default:
			std::cout << "Please enter a valid option" << std::endl;
			break;
		}


	} while (choice != 0);




		//Modify MetaData

		//Process wavfiles

		//Export into CSV file


























		std::string chosenWavFile;

	//////////////// Read in the wav files



	// write file
	/**
	std::ofstream outfile ("waves/outfile.wav", std::ios::binary | std::ios::out);

	test.writeHeader(&outfile);
	test.writeAudio(&outfile, buffer);
	file.close();
	**/

	///////////////







	// PROCESS FOR ECHO

	/**

	Processor *processorEcho = new NoiseGate(0.5);
	processorEcho-> processMono(test.data_bytes, buffer);

	//WRITTEN INTO ANOTHER FILE (NEW)
	std::ofstream outfile ("waves/outfile.wav", std::ios::binary | std::ios::out);

	test.writeHeader(&outfile);
	test.writeAudio(&outfile, buffer);
	file.close();

	**/
	// TESTING ON 8-BIT MONO
	//ECHO








	//Menu menu();









	return 0;
}
