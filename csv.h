#ifndef CSV_H
#define CSV_H
#include "header.h"
#include "16_bit_stereo.h"

class CSV: public header, public metadataIO{

std::string fileName;

public:

	CSV();	

	CSV(std::string file);

	std::string getFileName() const;
	
	void setFileName(std::string newFileName);
	
	void writeCSV(std::string fileN, std::ifstream *file, header obj, metadataIO &obj2);

};
#endif //CSV_H
