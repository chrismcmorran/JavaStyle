//
// Created by Christopher McMorran on 2016-12-15.
//

#ifndef JAVASTYLE_RUNTIME_H
#define JAVASTYLE_RUNTIME_H


#include "../lang/String.h"

class Runtime
{
public:
	static String exec(String command);
};


#endif //JAVASTYLE_RUNTIME_H
