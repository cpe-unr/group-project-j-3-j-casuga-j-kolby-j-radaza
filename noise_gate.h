#ifndef NOISE_GATE_H
#define NOISE_GATE_H
#include "processor.h"
/**
 * This is the Noise Gate Class that inherits from Processor 
 * Made by Justin Casuga
 */

class NoiseGate: public Processor{

double amp;
public:

	/**
 	* This is the inherited abstract function from processor that is overidded to handle 8 bit mono noise gate processing
 	*/
	void processMono(int size, unsigned char* buffer);

	/**
 	 * This is the inherited abstract function from processor that is overidded to handle 8 bit stereo noise gate processing
	 */
	void processStereo(int size, unsigned char* bufferL, unsigned char* bufferR);

	/**
 	 * This is the inherited abstract function from processor that is overidded to handle 16 bit mono noise gate processing
	 */
	void processMono(int size, short* buffer);

	/**
 	 * This is the inherited abstact function from processsor that is overidded to handle 16 bit stereo noise gate processing
	 */
	void processStereo(int size, short* bufferL, short* bufferR);

	/**
	 * This is Noise Gate's default constructor
	 */
	NoiseGate();

	/**
	 * This is Noise Gate's parameterized constructor
	 * @param nAmp - The amplitude that affects noise gate processing
	 */
	NoiseGate(double nAmp);

	/**
	 * This is Noise Gate's getter for the private attribute Amp
	 */
	double getAmp();

	/**
	 * This is Noise Gate's setter for the private attribute Amp
	 * @param nAmp - The amplitude that gets passed in
	 */
	void setAmp(double nAmp);

};
#endif //NOISE_GATE_H
