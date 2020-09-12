#ifndef TEST_H
#define TEST_H

#include <iostream>

#define ASSERT(assert, message) \
    if (!assert) { \
        std::cout << message << std::endl; \
        return 1; \
    } \

extern int TEST_FAIL;
extern int TEST_TOTAL;
#define TEST(test) \
    if (test) { \
        TEST_FAIL++; \
    } \
    TEST_TOTAL++;

#endif // TEST_H