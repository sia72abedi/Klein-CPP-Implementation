cmake_minimum_required(VERSION 3.15)
project(CPPKlein)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPPKlein main.cpp Data.cpp Data.h State.cpp State.h RoundKey.cpp RoundKey.h Klein.cpp Klein.h)