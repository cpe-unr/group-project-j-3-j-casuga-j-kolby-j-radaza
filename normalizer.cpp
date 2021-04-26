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
		if(buffer[i] > max){
			max = buffer[i];
		}
	}
	
	for(int i = 0; i < size-1; i++){
		if(buffer[i] < max){
			int sum = 0;
			sum = max - buffer[i];
			buffer[i] = sum;
		}
	}
}
	
void Normalizer::processStereo(int sizeL, int sizeR, unsigned char* bufferL, unsigned char* bufferR){

	for(int i = 0; i < sizeL-1; i++){
		if(bufferL[i] > max){
			max = bufferL[i];
		}
	}

	for(int i = 0; i < sizeR-1; i++){
		if(bufferR[i] > max){
			max = bufferR[i];
		}
	}

	for(int i = 0; i < sizeL-1; i++){
		if(bufferL[i] < max){
			int sum = 0;
			sum = max - bufferL[i];
			bufferL[i] = sum;
		}
	}

	for(int i = 0; i < sizeR-1; i++){
		if(bufferR[i] < max){
			int sum = 0;
			sum = max - bufferR[i];
			bufferR[i] = sum;
		}
	}
}

void Normalizer::processMono(int size, short* buffer){
	
	for(int i = 0; i < size-1; i++){
		if(buffer[i] > max){
			max = buffer[i];
		}
	}
	
	for(int i = 0; i < size-1; i++){
		if(buffer[i] < max){
			short sum = 0;
			sum = max - buffer[i];
			buffer[i] = sum;
		}
	}
}

void Normalizer::processStereo(int sizeL, int sizeR, short* bufferL, short* bufferR){

	for(int i = 0; i < sizeL-1; i++){
		if(bufferL[i] > max){
			max = bufferL[i];
		}
	}

	for(int i = 0; i < sizeR-1; i++){
		if(bufferR[i] > max){
			max = bufferR[i];
		}
	}

	for(int i = 0; i < sizeL-1; i++){
		if(bufferL[i] < max){
			int sum = 0;
			sum = max - bufferL[i];
			bufferL[i] = sum;
		}
	}

	for(int i = 0; i < sizeR-1; i++){
		if(bufferR[i] < max){
			int sum = 0;
			sum = max - bufferR[i];
			bufferR[i] = sum;
		}
	}
}

int Normalizer::getMax(){
	return max;
}
void Normalizer::setMax(int nMax){
	max = nMax;
}

