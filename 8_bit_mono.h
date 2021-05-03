#ifndef EIGHT_BIT_MONO
#define EIGHT_BIT_MONO
#include <fstream>
#include "header.h"

class Mono8Bit : public header {
public:
	Mono8Bit();
	~Mono8Bit();
	unsigned char* readAudio(std::ifstream *file);
	void writeAudio(std::ofstream *file, unsigned char* buffer);
};

#endif
