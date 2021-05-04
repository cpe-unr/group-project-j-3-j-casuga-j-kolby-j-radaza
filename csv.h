#ifndef CSV_H
#define CSV_H
#include "header.h"

class CSV: public header{

std::string fileName;

public:

	CSV();	

	CSV(std::string file);

	std::string getFileName() const;
	
	void setFileName(std::string newFileName);
	
	void writeCSV(std::string file, waveheader obj);

};
#endif //CSV_H
