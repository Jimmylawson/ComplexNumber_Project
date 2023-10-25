cmake_minimum_required(VERSION 3.26)
project(P03318OseiJ)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(P03318OseiJ
        complex.h
        P03ComplexNumbersDriver.cpp)
