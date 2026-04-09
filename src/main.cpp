#include <iostream>
#include "calculator.h"

int main() {
    Calculator calc;
    std::cout << "5 + 3 = " << calc.add(5, 3) << std::endl;
    std::cout << "10 - 4 = " << calc.subtract(10, 4) << std::endl;
    return 0;    // 0 = success (non-zero = error — Jenkins checks this)
}
