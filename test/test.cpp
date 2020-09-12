#include "test.h"

#include <iostream>

#include "math/UtilsTest.cpp"

int TEST_FAIL = 0;
int TEST_TOTAL = 0;

int main(int, char**) {
    run_math_tests();

    std::cout << (TEST_TOTAL - TEST_FAIL) << "/" << TEST_TOTAL << " tests successful, " << ( (100.0*TEST_FAIL) /TEST_TOTAL) << "% failed" << std::endl;
}
