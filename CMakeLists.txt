cmake_minimum_required(VERSION 3.6)
project(JavaStyle)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp util/Scanner.cpp util/Scanner.h io/File.cpp io/File.h lang/String.cpp lang/String.h lang/System.h lang/PrintStream.cpp lang/PrintStream.h util/ArrayList.h io/Runtime.cpp io/Runtime.h net/InetAddress.cpp net/InetAddress.h)
add_executable(JavaStyle ${SOURCE_FILES})