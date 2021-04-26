#include "noise_gate.h"

using namespace std;

NoiseGate::NoiseGate(){
	amp = 0;
}

NoiseGate::NoiseGate(double nAmp){
	amp = nAmp;
}

void NoiseGate::processMono(int size, unsigned char* buffer){

	for(int i = 0; i < size-1; i++){
		if(buffer[i]*amp < 129*amp){
			 buffer[i] = 128;
		}
		if(buffer[i]*amp > 129*amp){
			 buffer[i] = 128;
		}
	}
}

void NoiseGate::processStereo(int sizeL, int sizeR, unsigned char* bufferL, unsigned char* bufferR){
	
	for(int i = 0; i < sizeL-1; i++){
		if(bufferL[i]*amp < 129*amp){
			 bufferL[i] = 128;
		}
		else if(bufferL[i]*amp > 129*amp){
			 bufferL[i] = 128;
		}
	}

	for(int i = 0; i < sizeR-1; i++){
		if(bufferR[i]*amp < 129*amp){
			 bufferR[i] = 128;
		}
		else if(bufferR[i]*amp > 129*amp){
			 bufferR[i] = 128;
		}
	}
}

void NoiseGate::processMono(int size, short* buffer){

}

void NoiseGate::processStereo(int sizeL, int sizeR, short* bufferL, short* bufferR){

}


double NoiseGate::getAmp(){
	return amp;
}
void NoiseGate::setAmp(double nAmp){
	amp = nAmp;
}
