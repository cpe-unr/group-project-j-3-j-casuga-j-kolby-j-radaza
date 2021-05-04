#include "csv.h"
#include <fstream>

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
	
	void CSV::writeCSV(string file, waveheader obj){
	
		fstream outFile;
	
		outFile.open(file, ios_base::out);
		if(!outFile.is_open()){
			cerr << "Failed to create " << file << endl;
		}
		else{
			
		}
	}
