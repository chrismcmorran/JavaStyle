//
// Created by Christopher McMorran on 2016-12-14.
//

#include <iostream>
#include <sstream>
#include "String.h"

std::string String::toStdString()
{
	return this->_string;
}

void String::print()
{
	std::cout << this->_string;
}

String &String::reverse()
{
	std::string replacement = "";
	for (int i = (int) (this->_string.length() - 1); i > -1; --i)
	{
		replacement += this->_string.at((unsigned long) i);
	}
	this->_string = replacement;
	return *this;
}

String::String(const std::string &_string) : _string(_string)
{
	this->_string = _string;
}

int String::length()
{
	return (int) this->_string.length();
}

int String::indexOf(char character)
{
	for (int i = 0; i < this->_string.length(); ++i)
	{
		if (this->_string.at((unsigned long) i) == character) {
			return i;
		}
	}
	return -1;
}

char String::charAt(int index)
{
	return this->_string.at((unsigned long) index);
}

std::ostream &operator<<(std::ostream &os, const String &string)
{
	os << string._string;
	return os;
}

String &String::append(String string)
{
	this->_string += string._string;
	return *this;
}

String &String::append(std::string string)
{
	this->_string += string;
	return *this;
}

String &String::append(char *string)
{
	this->_string += std::string(string);
	return *this;
}
