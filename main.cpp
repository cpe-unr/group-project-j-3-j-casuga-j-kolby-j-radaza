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
/** TEMPLETIZED FUNCTION for reading in all the audioFiles (separately)

template <typename T>
void readWavFile(std::string fileName,T audioClass){

}
**/


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
		std::cout << "[4] 26-bit stereo" << std::endl;
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
			//Processor *processorEcho = new Echo(15);
			//processorEcho-> processMono(mono_8_wavFile.fileHeader.data_bytes, mono_8_buffer);
			break;
		}

		case 2:{
			Menu<Stereo8Bit,unsigned char*, unsigned char*, unsigned char*> menu(&stereo_8_wavFile,stereo_8_name, stereo_8_buffer_L, stereo_8_buffer_R);
			break;
		}


		case 3:{
			Menu<Mono16Bit,short*, short*, short*> menu(&mono_16_wavFile,mono_16_name, mono_16_buffer);
			break;
		}

		case 4:{
			  Menu<Stereo16Bit,short*, short*, short*> menu(&stereo_16_wavFile,stereo_16_name, stereo_16_buffer_L, stereo_16_buffer_R);
			break;
		}

		default:
			std::cout << "Please enter a valid option" << std::endl;
			break;
		}


	} while (choice != 0); // change this to when the bool flag for process done is over.




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
