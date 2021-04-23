#include "normalizer.h"

using namespace std;

Normalizer::Normalizer(){
	max = 0;
}
Normalizer::Normalizer(int nMax){
	max = nMax;
}

void Normalizer::process(int size, unsigned char* metaData){

	for(int i = 0; i < size-1; i++){
		if(metaData[i] < max){
			metaData[i] = max;
		}
	}
}
	
void Normalizer::processStereo(int sizeL, int sizeR, unsigned char* metaDataL, unsigned char* metaDataR){

	for(int i = 0; i < sizeL-1; i++){
		if(metaDataL[i] < max){
			metaDataL[i] = max;
		}
	}

	for(int i = 0; i < sizeR-1; i++){
		if(metaDataR[i] < max){
			metaDataR[i] = max;
		}
	}

}

int Normalizer::getMax(){
	return max;
}
void Normalizer::setMax(int nMax){
	max = nMax;
}

