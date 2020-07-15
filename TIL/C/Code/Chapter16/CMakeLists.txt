cmake_minimum_required(VERSION 3.16)
project(Chapter16)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=CP949")

add_executable(Chapter16 fseek.c)