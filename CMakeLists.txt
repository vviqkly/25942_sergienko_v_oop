cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

cmake_minimum_required(VERSION 3.15)
project(task5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(funcs STATIC
    funcs.cpp
    funcs.h
)

target_include_directories(funcs PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(app main.cpp)

target_link_libraries(app PRIVATE funcs)