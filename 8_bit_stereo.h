#ifndef 8_BIT_STEREO_H
#define 8_BIT_STEREO_H
#include "WaveHeader.h"

class 8BitStereo : public Sound{
public:
	waveHeader fileHeader;
	unsigned char* bufferL;
	unsigned char* bufferR;
	unsigned char* readBuffer(const std::string &fileName);
};
#endif
