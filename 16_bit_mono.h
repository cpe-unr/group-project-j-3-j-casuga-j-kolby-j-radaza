#ifndef 16_BIT_MONO_H
#define 16_BIT_MONO_H
#include "WaveHeader.h"

class 16BitMono : public waveHeader {
public:
	waveHeader fileHeader;
	short buffer;
	short readBuffer(const std::string &fileName);
};

#endif
