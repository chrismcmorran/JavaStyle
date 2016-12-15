#include <iostream>
#include "lang/String.h"
#include "util/Scanner.h"
#include "lang/System.h"
#include "util/HashMap.h"

int main() {
	Scanner scanner("Makefile");
	HashMap<String, String> map;
	ArrayList<String> whoa;
	String whoastr("lol");
	whoa.addFirst(&whoastr);
	System::println(whoa.removeFirst().toStdString());
	String temp = scanner.readline();

	while (temp.length() > 0) {
		System::println(temp);
		temp = scanner.readline();
	}

    return 0;
}