#include "math/Utils.h"

void math_tests() {
    VEC3 res = directionInFrame(VEC3(1.0, 2.0, 3.0), DEFAULT_QUAT);
    std::cout << res << std::endl;
}