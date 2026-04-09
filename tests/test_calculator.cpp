#include <gtest/gtest.h>
#include "calculator.h"

// Test case for the Addition function
TEST(CalculatorTests, AdditionTrue) {
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-1, 1), 0);
}

// Test case for the Subtraction function
TEST(CalculatorTests, SubtractionTrue) {
    Calculator calc;
    EXPECT_EQ(calc.subtract(10, 5), 5);
}

// Test case for the Multiplication function
TEST(CalculatorTests, MultiplicationTrue) {
    Calculator calc;
    EXPECT_EQ(calc.multiply(3, 4), 12);
}
