//
// Created by Christopher McMorran on 2016-12-14.
//

#include <iostream>
#include "Scanner.h"


Scanner::Scanner(File *file)
{
	this->istream_mode = false;
//	*this->_ifstream = *file->_stream;
	this->_stringstream = new std::stringstream();
	fill_stream();
}

Scanner::~Scanner()
{
	delete(this->_ifstream);
	delete(this->_stringstream);
}

Scanner::Scanner(String *string)
{
	this->istream_mode = false;
	this->_ifstream = new std::ifstream(string->_string);
	this->_stringstream = new std::stringstream();
	this->_ifstream->open("r");
	this->fname = string->_string;
	fill_stream();
}

Scanner::Scanner(std::string string)
{
	this->_ifstream = new std::ifstream(string);
	this->_stringstream = new std::stringstream();
	this->_ifstream->open("r");
	this->fname = string;
	fill_stream();
}

bool Scanner::isOpen()
{
	return this->_ifstream->is_open();
}

bool Scanner::isClosed()
{
	return !this->_ifstream->is_open();
}

bool Scanner::open()
{
	this->_ifstream->open(this->fname.c_str());
	return this->_ifstream->is_open();
}

String Scanner::readline()
{
	if (istream_mode)
	{
		std::string line;
		std::getline(std::cin, line);
		return String(line);
	}

	if (this->strings.size() > 0)
	{
		String line(this->strings.front());
		this->strings.pop_front();
		return line;
	}
	return String("");
}

void Scanner::fill_stream()
{
	*this->_stringstream << this->_ifstream->rdbuf();
	std::string temp = "";
	std::string buffer = this->_stringstream->rdbuf()->str();
	for (unsigned long i = 0; i < buffer.length(); ++i)
	{
		temp += buffer.at(i);
		if (buffer.at(i) == '\n') {
			strings.push_back(temp);
			temp = "";
		}
	}
}

bool Scanner::hasNext()
{
	return this->strings.size() > 0;
}

bool Scanner::isEmpty()
{
	return this->strings.size() < 1;
}

bool Scanner::close()
{
	this->_ifstream->close();
	return !this->_ifstream->is_open();
}

Scanner::Scanner(std::istream &input)
{
	this->istream_mode = true;
}
