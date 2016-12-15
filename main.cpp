#include <iostream>
#include "lang/String.h"
#include "util/Scanner.h"
#include "lang/System.h"

int main() {
	Scanner scanner("Makefile");
	String temp = scanner.readline();

	while (temp.length() > 0) {
		System::println(temp);
		temp = scanner.readline();
	}

    return 0;
}