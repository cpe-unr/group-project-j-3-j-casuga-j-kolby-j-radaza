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
	
void Normalizer::processStereo(int size, unsigned char* bufferL, unsigned char* bufferR){

	for(int i = 0; i < size-1; i++){
		if(bufferL[i] > max){
			max = bufferL[i];
		}
	}

	for(int i = 0; i < size-1; i++){
		if(bufferR[i] > max){
			max = bufferR[i];
		}
	}

	for(int i = 0; i < size-1; i++){
		if(bufferL[i] < max){
			int sum = 0;
			sum = max - bufferL[i];
			bufferL[i] = sum;
		}
	}

	for(int i = 0; i < size-1; i++){
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
		if(buffer[i] > 0){
			if(buffer[i] < max){
				int sum = 0;
				sum = max - buffer[i];
				buffer[i] = sum;
			}
		}
		else if (buffer[i] < 0){
			if(buffer[i] > -max){
				int sum = 0;
				sum = -max - buffer[i];
				buffer[i] = sum;
			}
		}
	}
}

void Normalizer::processStereo(int size, short* bufferL, short* bufferR){

	for(int i = 0; i < size-1; i++){
		if(bufferL[i] > max){
			max = bufferL[i];
		}
	}

	for(int i = 0; i < size-1; i++){
		if(bufferR[i] > max){
			max = bufferR[i];
		}
	}

	for(int i = 0; i < size-1; i++){
		if(bufferL[i] > 0){		
			if(bufferL[i] < max){
				int sum = 0;
				sum = max - bufferL[i];
				bufferL[i] = sum;
			}
		}
		else if (bufferL[i] < 0){
			if(bufferL[i] > -max){
				int sum = 0;
				sum = -max - bufferL[i];
				bufferL[i] = sum;
			}
		}
		
		
	}

	for(int i = 0; i < size-1; i++){
		if(bufferR[i] > 0){
			if(bufferR[i] < max){
				int sum = 0;
				sum = max - bufferR[i];
				bufferR[i] = sum;
			}
		}
		else if (bufferR[i] < 0){
			if(bufferR[i] > -max){
				int sum = 0;
				sum = -max - bufferR[i];
				bufferR[i] = sum;
			}
		}
	}
}

int Normalizer::getMax(){
	return max;
}
void Normalizer::setMax(int nMax){
	max = nMax;
}

