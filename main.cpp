#include <iostream>
#include "lang/String.h"
#include "util/Scanner.h"
#include "lang/System.h"
#include "util/ArrayList.h"

int main() {
	Scanner scanner("Makefile");
	ArrayList<String> whoa;
	String whoastr("lol");
	whoa.addFirst(&whoastr);
	System::println(whoa.removeFirst().toStdString());
	String temp = scanner.readline();

	while (scanner.hasNext())
	{
		System::println(temp);
		temp = scanner.readline();
	}

	ArrayList<std::string> strs;
	strs.add("hello there");
	System::println(strs.getFirst());
	strs.add("hello world.");
	System::println(strs.getLast());

    return 0;
}