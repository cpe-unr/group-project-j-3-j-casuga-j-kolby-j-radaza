#include "echo.h"

using namespace std;

Echo::Echo(){
	delay = 0;
}

Echo::Echo(int nDelay){
	delay = nDelay;
}

void Echo::processMono(int size, unsigned char* metaData){

	for(int i = 0; i < size-1; i++){
		if((metaData[i]) > 110){
		}
		else{
			metaData[i] = metaData[i] + metaData[i-delay];
		}
	}
}
	
void Echo::processStereo(int sizeL, int sizeR, unsigned char* metaDataL, unsigned char* metaDataR){

	for(int i = 0; i < sizeL-1; i++){
		if((metaDataL[i]) > 110){
		}
		else{
			metaDataL[i] = metaDataL[i] + metaDataL[i-delay];
		}
	}

	for(int i = 0; i < sizeR-1; i++){
		if((metaDataR[i]) > 110){
		}
		else{
			metaDataR[i] = metaDataR[i] + metaDataR[i-delay];
		}
	}
}

int Echo::getDelay(){
	return delay;
}

void Echo::setDelay(int nDelay){
	delay = nDelay;
}
