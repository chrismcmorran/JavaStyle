//
// Created by Christopher McMorran on 2016-12-15.
//

#include "InetAddress.h"
#include "../io/Runtime.h"

String InetAddress::getExternalAddress()
{
	String addr = Runtime::exec("curl -s http://www.icanhazip.com");
	return addr.subString(1, addr.indexOf('\0'));
}
