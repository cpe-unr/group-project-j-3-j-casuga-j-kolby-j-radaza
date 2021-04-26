#include "normalizer.h"

using namespace std;

Normalizer::Normalizer(){
	max = 0;
}
Normalizer::Normalizer(int nMax){
	max = nMax;
}

void Normalizer::processMono(int size, unsigned char* buffer){

	for(int i = 0; i < size-1; i++){
		if(buffer[i] < max){
			buffer[i] = max;
		}
	}
}
	
void Normalizer::processStereo(int sizeL, int sizeR, unsigned char* bufferL, unsigned char* bufferR){

	for(int i = 0; i < sizeL-1; i++){
		if(bufferL[i] < max){
			bufferL[i] = max;
		}
	}

	for(int i = 0; i < sizeR-1; i++){
		if(bufferR[i] < max){
			bufferR[i] = max;
		}
	}

}

void Normalizer::processMono(int size, unsigned short* buffer){}

void Normalizer::processStereo(int sizeL, int sizeR, unsigned short* bufferL, unsigned short* bufferR){}

int Normalizer::getMax(){
	return max;
}
void Normalizer::setMax(int nMax){
	max = nMax;
}

