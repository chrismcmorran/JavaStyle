//
// Created by Christopher McMorran on 2016-12-15.
//

#include "pstream.h"
#include "../util/Scanner.h"
#include "../lang/System.h"
#include "Runtime.h"


String Runtime::exec(String command)
{
	redi::ipstream processInputStream(command._string.c_str());
	std::stringstream buffer;
	buffer << processInputStream.rdbuf();
	return buffer.str();
}
