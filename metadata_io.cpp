#include <fstream>
#include <iostream>
#include "metadata.h"
#include "metadata_io.h"

metadataIO::metadataIO () {}
metadataIO::~metadataIO () {}

void metadataIO::readMetadata(std::ifstream *file) {
	if (file->is_open()) {
		file->read((char *) &Metadata, sizeof(Metadata));
	} else {
		std::cout << "Failed to read metadata from file" <<std::endl;
	}
}

void metadataIO::writeMetadata(std::ofstream *file) {
	if (file->is_open()) {
		file->write((char *)&Metadata, sizeof(Metadata));
	} else {
		std::cout << "Cannot write metadata to file" << std::endl;
	}
}
