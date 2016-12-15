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

String::String(const char *string)
{
	this->_string.append(string);
}

String &String::remove(String string)
{
	this->_string.erase(this->_string.find(string._string), (unsigned long) string.length());
	return *this;
}


String &String::subString(int start, int end)
{
	this->_string.substr((unsigned long) start, (unsigned long) end);
	return *this;
}

String &String::replaceAll(std::string const &original, std::string const &from, std::string const &to)
{
	std::string results;
	std::string::const_iterator end = original.end();
	std::string::const_iterator current = original.begin();
	std::string::const_iterator next = std::search(current, end, from.begin(), from.end());
	while (next != end)
	{
		results.append(current, next);
		results.append(to);
		current = next + from.size();
		next = std::search(current, end, from.begin(), from.end());
	}
	results.append(current, next);
	this->_string = results;
	return *this;
}



