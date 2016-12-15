//
// Created by Christopher McMorran on 2016-12-14.
//

#include "File.h"

File::File(std::string fileName)
{
	this->_stream = new std::ifstream(fileName);
}

File::~File()
{
	delete(this->_stream);
}

File::File(char *fileName)
{
	this->_stream = new std::ifstream(fileName);
}

File::File(String fileName)
{
	this->_stream = new std::ifstream(fileName.toStdString());
}
