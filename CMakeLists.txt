cmake_minimum_required(VERSION 3.23)
project(algebra)

set(CMAKE_CXX_STANDARD 20)

add_executable(algebra main.cpp utils/html_generator/elements.h utils/html_generator/elements.cpp utils/io/io.cpp utils/io/io.h)
