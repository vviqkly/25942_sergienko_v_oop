cmake_minimum_required(VERSION 3.16)
project(OOP_08)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task8 main.cpp)
option(BUILD_TESTS "build googletest tests" OFF)

IF(BUILD_TESTS)
	enable_testing()
	ass_subdirectore(tests)
endif()
