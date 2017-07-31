cmake_minimum_required(VERSION 3.7)
project(MS5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        AmaPerishable.cpp
        AmaPerishable.h
#        AmaPerishableTester.cpp
        AmaProduct.cpp
        AmaProduct.h
        AmaProductTester.cpp
        Date.cpp
        Date.h
        ErrorMessage.cpp
        ErrorMessage.h
        general.h
        MyFile.cpp
        MyFile.h
        Product.cpp
        Product.h
        Streamable.h)

add_executable(MS5 ${SOURCE_FILES})