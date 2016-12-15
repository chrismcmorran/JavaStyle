//
// Created by Christopher McMorran on 2016-12-15.
//

#include <iostream>
#include "PrintStream.h"

PrintStream::PrintStream(String file)
{
	this->_stream = new std::ofstream(file._string.c_str());
	this->fname = file._string;
}

PrintStream::PrintStream(std::string file)
{
	this->_stream = new std::ofstream(file.c_str());
	this->fname = file;
}

PrintStream::~PrintStream()
{
	delete(this->_stream);
}

bool PrintStream::open()
{
	this->_stream->open(this->fname);
	return this->_stream->is_open();
}

bool PrintStream::close()
{
	this->_stream->close();
	return !this->_stream->is_open();
}

bool PrintStream::isOpen()
{
	return this->_stream->is_open();
}

bool PrintStream::isClosed()
{
	return !this->_stream->is_open();
}

PrintStream &PrintStream::append(String string)
{
	this->_stream->write(string._string.c_str(), string.length());
	return *this;
}

PrintStream &PrintStream::append(std::string string)
{
	this->_stream->write(string.c_str(), string.length());
	return *this;
}

PrintStream &PrintStream::println(std::string string)
{
	if (this->is_static) {
		std::cout << string;
		return *this;
	}

	this->_stream->write(string.append("\n").c_str(), string.length() + 1);
	return *this;
}

PrintStream &PrintStream::println(String string)
{
	if (this->is_static) {
		std::cout << string;
		return *this;
	}

	this->_stream->write(string.append("\n")._string.c_str(), string.length() + 1);
	return *this;
}
