#include "noise_gate.h"

using namespace std;

NoiseGate::NoiseGate(){
	amp = 0;
}

NoiseGate::NoiseGate(double nAmp){
	amp = nAmp;
}

void NoiseGate::processMono(int size, unsigned char* metaData){

	for(int i = 0; i < size-1; i++){
		if(metaData[i]*amp < 129*amp){
			 metaData[i] = 128;
		}
	}
}

void NoiseGate::processStereo(int sizeL, int sizeR, unsigned char* metaDataL, unsigned char* metaDataR){
	
	for(int i = 0; i < sizeL-1; i++){
		if(metaDataL[i]*amp < 129*amp){
			 metaDataL[i] = 128;
		}
	}

	for(int i = 0; i < sizeR-1; i++){
		if(metaDataR[i]*amp < 129*amp){
			 metaDataR[i] = 128;
		}
	}
}

double NoiseGate::getAmp(){
	return amp;
}
void NoiseGate::setAmp(double nAmp){
	amp = nAmp;
}
