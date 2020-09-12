#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#include "math/Types.h"

namespace cuda_render {

class Entity;

namespace utils {

VEC3 xAxisOf(QUAT q);
VEC3 yAxisOf(QUAT q);
VEC3 zAxisOf(QUAT q);
QUAT toQuat(VEC3 xAxis, VEC3 yAxis);
QUAT toQuat(VEC3 xAxis, VEC3 yAxis, VEC3 zAxis);
VEC4 toVec4(QUAT q);

FLOAT rand();
VEC3 randomVec3();
MAT3 randomRot();

QUAT headRotationQuat(VEC3 lookingDirection, VEC3 currentRightDirection, VEC3 upDirection = Directions::UP);

VEC3 pointInFrame(VEC3 vector, Entity& frame);
VEC3 directionInFrame(VEC3 direction, Entity& frame);
VEC3 directionInFrame(VEC3 direction, QUAT orientation);

std::ostream &operator<<(std::ostream &output, const VEC3& v);
std::ostream &operator<<(std::ostream &output, const QUAT& v);
std::ostream &operator<<(std::ostream &output, const MAT3& v);
std::ostream &operator<<(std::ostream &output, const MAT4& v);

#define EPS 1e-10
bool floatEqual(FLOAT f1, FLOAT f2);
bool floatEqual(VEC3 v1, VEC3 v2);
bool floatEqual(QUAT q1, QUAT q2);

} //namespace utils
} //namespace cuda_render

#endif //UTILS_H