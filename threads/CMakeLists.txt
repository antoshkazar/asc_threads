cmake_minimum_required(VERSION 3.20)
project(threads)

set(CMAKE_CXX_STANDARD 14)

add_executable(threads main.cpp client.cpp hotel.cpp)
