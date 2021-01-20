cmake_minimum_required(VERSION 3.17)
project(SLY)

set(CMAKE_CXX_STANDARD 14)

add_executable(SLY main.cpp Methods/Newton/Newton.cpp Methods/Newton/Newton.h Methods/Bijection/Bijection.cpp Methods/Bijection/Bijection.h)