//
// Created by Christopher McMorran on 2016-12-14.
//

#ifndef JAVASTYLE_FILE_H
#define JAVASTYLE_FILE_H


#include <fstream>
#include "../lang/String.h"

class File
{
	friend class Scanner;
private:
	std::ifstream* _stream;
public:
	File(std::string fileName);
	File(char* fileName);
	File(String fileName);

	virtual ~File();
};


#endif //JAVASTYLE_FILE_H
