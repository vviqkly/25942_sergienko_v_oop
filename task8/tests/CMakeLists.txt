include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(sensor_tests tests.cpp)

target_include_directories(sensor_tests PRIVATE ..)
target_link_libraries(sensor_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(sensor_tests)
