cmake_minimum_required(VERSION 3.14)
project(MyProject VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library
add_library(calculator_lib src/calculator.cpp)
target_include_directories(calculator_lib PUBLIC include)

# Main executable
add_executable(MyApp src/main.cpp)
target_link_libraries(MyApp PRIVATE calculator_lib)

# Tests — FetchContent downloads GTest automatically, no install needed
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # ← critical for Windows MSVC
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(tests)
