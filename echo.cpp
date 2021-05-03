#include "echo.h"

using namespace std;

Echo::Echo(){
	delay = 0;
}

Echo::Echo(int nDelay){
	delay = nDelay;
}

void Echo::processMono(int size, unsigned char* buffer){

	for(int i = 0; i < size-1; i++){
		if((buffer[i]) > 110){
		}
		else{
			buffer[i] = buffer[i] + buffer[i-delay];
		}
	}
}
	
void Echo::processStereo(int sizeL, int sizeR, unsigned char* bufferL, unsigned char* bufferR){

	for(int i = 0; i < sizeL-1; i++){
		if((bufferL[i]) > 110){
		}
		else{
			bufferL[i] = bufferL[i] + bufferL[i-delay];
		}
	}

	for(int i = 0; i < sizeR-1; i++){
		if((bufferR[i]) > 110){
		}
		else{
			bufferR[i] = bufferR[i] + bufferR[i-delay];
		}
	}
}

void Echo::processMono(int size, short* buffer){

	for(int i = 0; i < size-1; i++){
		if((buffer[i]) > 14090){
		}
		else if ((buffer[i]) < -14090){
		}
		else{
			buffer[i] = buffer[i] + buffer[i-delay];
		}
	}
}

void Echo::processStereo(int sizeL, int sizeR, short* bufferL, short* bufferR){

	for(int i = 0; i < sizeL-1; i++){
		if((bufferL[i]) > 14090){
		}
		else if ((bufferL[i]) < -14090){
		}
		else{
			bufferL[i] = bufferL[i] + bufferL[i-delay];
		}
	}

	for(int i = 0; i < sizeR-1; i++){
		if((bufferR[i]) > 14090){
		}
		else if ((bufferR[i]) < -14090){
		}
		else{
			bufferR[i] = bufferR[i] + bufferR[i-delay];
		
		}
	}

}


int Echo::getDelay(){
	return delay;
}

void Echo::setDelay(int nDelay){
	delay = nDelay;
}
