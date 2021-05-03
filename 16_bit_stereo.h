#ifndef 16_BIT_STEREO_H
#define 16_BIT_STEREO_H
#include "read_file.h"

class 16BitStereo : public readFile{
	16BitStereo();
	~16BitStereo();
public:
	waveHeader fileHeader;
	short bufferL;
	short bufferR;
	short readBuffer(const std::string &fileName);
};
#endif
