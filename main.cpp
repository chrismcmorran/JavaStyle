#include <iostream>
#include <zconf.h>
#include "lang/String.h"
#include "util/Scanner.h"
#include "lang/System.h"
#include "util/ArrayList.h"
#include "io/Runtime.h"
#include "net/InetAddress.h"

int main() {
	String user = Runtime::exec("whoami");
	String address = InetAddress::getExternalAddress();
	String prompt = user.append("@").append(address).append(" > ");
	Scanner scanner(std::cin);
	prompt.replaceAll(prompt.toStdString(), "\n", "");
	while (1)
	{
		System::print(prompt);
		System::println(Runtime::exec(scanner.readline()));
	}
    return 0;
}