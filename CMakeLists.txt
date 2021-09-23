cmake_minimum_required(VERSION 3.16)
project(long_arithmetic)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(LongArithmetic_run ${SOURCE_FILES})

include_directories(LongArithmetic)
add_subdirectory(LongArithmetic)

target_link_libraries(LongArithmetic_run LongArithmetic)

add_subdirectory(google_tests)

