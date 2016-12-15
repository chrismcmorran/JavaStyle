//
// Created by Christopher McMorran on 2016-12-15.
//

#ifndef JAVASTYLE_PRINTSTREAM_H
#define JAVASTYLE_PRINTSTREAM_H


#include <fstream>
#include "String.h"

class PrintStream
{
private:
	bool is_static = true;
	std::ofstream *_stream;
	std::string fname;
public:
	PrintStream(String file);
	PrintStream(std::string file);

	virtual ~PrintStream();

	bool open();
	bool close();
	bool isOpen();
	bool isClosed();

	PrintStream& append(String string);
	PrintStream& append(std::string string);

	PrintStream& println(std::string string);
	PrintStream& println(String string);
};


#endif //JAVASTYLE_PRINTSTREAM_H
