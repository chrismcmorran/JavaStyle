//
// Created by Christopher McMorran on 2016-12-15.
//

#ifndef JAVASTYLE_SYSTEM_H
#define JAVASTYLE_SYSTEM_H


#include <iostream>
#include "PrintStream.h"


class System
{
private:
public:
	static void println(String string) {
		std::cout << string << std::endl;
	}
	static void println(std::string string) {
		std::cout << string << std::endl;
	}

};


#endif //JAVASTYLE_SYSTEM_H
