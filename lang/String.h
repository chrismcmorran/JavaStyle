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

	friend class Runtime;
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
	String(const std::string &_string);

	String &remove(String string);

	String &subString(int start, int end);

	friend std::ostream &operator<<(std::ostream &os, const String &string);

	String(const char *string);

	String &replaceAll(std::string const &original, std::string const &from, std::string const &to);


};


#endif //JAVASTYLE_STRING_H
