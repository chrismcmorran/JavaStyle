//
// Created by Christopher McMorran on 2016-12-14.
//

#ifndef JAVASTYLE_SCANNER_H
#define JAVASTYLE_SCANNER_H


#include <iosfwd>
#include <sstream>
#include <fstream>
#include <stack>
#include <list>
#include "../io/File.h"

class Scanner
{
private:
	std::stringstream* _stringstream;
	std::ifstream* _ifstream;
	std::string fname;
	std::list<std::string> strings;
	void fill_stream();
public:
	Scanner(FILE *file);
	Scanner(File *file);
	Scanner(String *string);
	Scanner(std::string string);
	virtual ~Scanner();
	bool isOpen();
	bool isClosed();
	bool open();

	bool hasNext();

	bool isEmpty();

	bool close();
	String readline();

};


#endif //JAVASTYLE_SCANNER_H
