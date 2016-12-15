//
// Created by Christopher McMorran on 2016-12-15.
//

#include <ifaddrs.h>
#include <arpa/inet.h>
#include "InetAddress.h"
#include "../io/Runtime.h"

String InetAddress::getExternalAddress()
{
	String addr = Runtime::exec("curl -s http://www.icanhazip.com");
	return addr.subString(1, addr.indexOf('\0'));
}

String InetAddress::getLocalAddress()
{
	struct ifaddrs *ifap, *ifa;
	struct sockaddr_in *sa;
	char *addr;

	getifaddrs(&ifap);
	for (ifa = ifap; ifa; ifa = ifa->ifa_next)
	{
		if (ifa->ifa_addr->sa_family == AF_INET)
		{
			sa = (struct sockaddr_in *) ifa->ifa_addr;
			addr = inet_ntoa(sa->sin_addr);
			std::string name = ifa->ifa_name;
			if (name.find("en") != -1 || name.find("eth") != -1) return String(addr);
		}
	}
	freeifaddrs(ifap);
	return String("127.0.0.1");

}
