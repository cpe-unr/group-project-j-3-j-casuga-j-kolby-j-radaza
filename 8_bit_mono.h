#ifndef EIGHT_BIT_MONO
#define EIGHT_BIT_MONO
#include <fstream>
#include "read_file.h"

class Mono8Bit : public readFile {
public:
	Mono8Bit();
	~Mono8Bit();
	unsigned char* readAudio(std::ifstream file);
};

#endif
