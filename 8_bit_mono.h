#ifndef 8_BIT_MONO_H
#define 8_BIT_MONO_H
#include "WaveHeader.h"

class 8BitMono : public waveHeader {
public:
	waveHeader fileHeader;
	unsigned char* buffer;
	unsigned char* readBuffer(const std::string &fileName);
};

#endif
