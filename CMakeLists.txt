cmake_minimum_required(VERSION 3.14)
project(MyProject VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(calculator_lib src/calculator.cpp)
target_include_directories(calculator_lib PUBLIC include)

add_executable(MyApp src/main.cpp)
target_link_libraries(MyApp PRIVATE calculator_lib)

enable_testing()
add_subdirectory(tests)
