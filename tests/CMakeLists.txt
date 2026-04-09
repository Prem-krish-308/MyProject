add_executable(calculator_tests test_calculator.cpp)
target_link_libraries(calculator_tests
    PRIVATE calculator_lib GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(calculator_tests)
