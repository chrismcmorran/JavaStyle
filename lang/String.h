//
// Created by Christopher McMorran on 2016-12-14.
//

#ifndef JAVASTYLE_STRING_H
#define JAVASTYLE_STRING_H


#include <string>
#include <ostream>

class String
{
	friend class Scanner;
	friend class PrintStream;
private:
	std::string _string;
public:
	std::string toStdString();
	void print();
	String& reverse();
	int indexOf(char character);
	char charAt(int index);
	int length();
	String& append(String string);
	String& append(std::string string);
	String& append(char* string);
	String(const std::string &_string);

	friend std::ostream &operator<<(std::ostream &os, const String &string);
};


#endif //JAVASTYLE_STRING_H
