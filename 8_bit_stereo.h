#ifndef 8_BIT_STEREO_H
#define 8_BIT_STEREO_H
#include "header.h"

class 8BitStereo : public readFile{
public:
	waveHeader fileHeader;
	unsigned char* bufferL;
	unsigned char* bufferR;
	unsigned char* readBuffer(const std::string &fileName);
};
#endif
