
cmake_minimum_required(VERSION 3.16)

project(OOP_06)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(task_6_1 6_1/main.cpp)
add_executable(task_6_2 6_2/main.cpp)
add_executable(task_6_3 6_3/main.cpp)

add_executable(tests_6_2 6_2/tests.cpp)
target_link_libraries(tests_6_2 PRIVATE GTest::gtest_main)
gtest_discover_tests(tests_6_2)

add_executable(tests_6_3 6_3/tests.cpp)
target_link_libraries(tests_6_3 PRIVATE GTest::gtest_main)
gtest_discover_tests(tests_6_3)
