#include "test.h"
#include "math/Utils.h"

using namespace cuda_render;
using namespace cuda_render::utils;

int test_default_quat() {
    VEC3 v1 = VEC3(1.0, 2.0, 3.0);
    VEC3 v2 = directionInFrame(v1, DEFAULT_QUAT);
    ASSERT(floatEqual(v1, v2), "directionInFrame fails for default quaternion")
    return 0;
}

int test_quat_conversions() {
    VEC3 xAxis = VEC3(1.0, 0.0, 0.0);
    VEC3 yAxis = VEC3(0.0, 1.0, 0.0);
    VEC3 zAxis = VEC3(0.0, 0.0, 1.0);
    QUAT q = DEFAULT_QUAT;

    ASSERT(floatEqual(xAxis, xAxisOf(q)), "xAxis of default quaternion doesn't match unit x axis")
    ASSERT(floatEqual(yAxis, yAxisOf(q)), "yAxis of default quaternion doesn't match unit y axis")
    ASSERT(floatEqual(zAxis, zAxisOf(q)), "zAxis of default quaternion doesn't match unit z axis")
    ASSERT(floatEqual(q, toQuat(xAxis, yAxis)), "quaternion from 2 vectors doesn't match default quaternion")
    ASSERT(floatEqual(q, toQuat(xAxis, yAxis, zAxis)), "quaternion from 3 vectors doesn't match default quaternion")

    for (int i = 0; i < 10; i++) {
        MAT3 rot = randomRot();
        q = glm::quat_cast(rot);
        xAxis = xAxisOf(q);
        yAxis = yAxisOf(q);
        zAxis = zAxisOf(q);
        ASSERT(floatEqual(q, toQuat(xAxis, yAxis)), "quaternion from 2 vectors doesn't match random quaternion");
        ASSERT(floatEqual(q, toQuat(xAxis, yAxis, zAxis)), "quaternion from 3 vectors doesn't match random quaternion");
    }
}

void run_math_tests() {
    TEST(test_default_quat())
    TEST(test_quat_conversions())
}