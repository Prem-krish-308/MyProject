cmake_minimum_required(VERSION 3.10)
project(CalculatorProject)

# 1. Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# 2. Include directories (so we can find calculator.h)
include_directories(include)

# 3. Create a library for the calculator logic 
# This prevents code duplication between the main app and the tests
add_library(calc_lib src/calculator.cpp)

# 4. Create the main executable
add_executable(MyProject src/main.cpp)
target_link_libraries(MyProject calc_lib)

# 5. Setup Testing
enable_testing()

# Find GTest package (must be installed on the system/Jenkins agent)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create the test executable
add_executable(run_tests tests/test_calculator.cpp)
target_link_libraries(run_tests calc_lib GTest::GTest GTest::Main)

# Register the test with CTest
add_test(NAME AllCalculatorTests COMMAND run_tests)
