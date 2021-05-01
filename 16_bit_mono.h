#ifndef 16_BIT_MONO_H
#define 16_BIT_MONO_H
#include "read_file.h"

class 16BitMono : public readFile {
public:
	waveHeader fileHeader;
	short buffer;
	short readBuffer(const std::string &fileName);
};

#endif
