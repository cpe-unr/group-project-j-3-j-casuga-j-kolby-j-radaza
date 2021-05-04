#include "csv.h"
#include <fstream>
#include <iostream>

using namespace std;

	CSV::CSV(){
		fileName = " ";
	}

	CSV::CSV(string file){
		fileName = file;
	}
	
	string CSV::getFileName() const{
		return fileName;
	}
	
	void CSV::setFileName(string file){
		fileName = file;
	}
	
	void CSV::writeCSV(string fileN, ifstream *file, header obj, metadataIO obj2){
	
		obj.readHeader(file);
		obj2.readMetadata(file);
		fstream outFile;
	
		outFile.open(fileN, ios_base::out);
		if(!outFile.is_open()){
			std::cout << "Failed to create CSV file for " << file << endl;
		}
		else{
			outFile << obj.audio_format << ", " << obj.num_channels << ", " << obj.sample_rate << ", " << obj.byte_rate << ", " << obj.sample_alignment << ", " << obj.bit_depth << ", ";
		    if(obj2.inam[0] == ' ' || obj2.inam[1] == ' ' || obj2.inam[2] == ' ' || obj2.inam[3] == ' ' || obj2.inam[4] == ' '){
				outFile << "No metadata present" << endl;
		    } else{
				for(int i = 0; i < 5; i++){
					outFile << obj2.inam[i] << ", " << obj2.iart[i] << ", " << obj2.iprd[i] << ", " << obj2.ignr[i] << obj2.icrd[i] << obj2.itrk[i] << ", " << obj2.icmt[i];
				}
			}
		}
	}
