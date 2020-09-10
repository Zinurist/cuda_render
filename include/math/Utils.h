#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#include "math/Types.h"

class Entity;

MAT4 headRotationMatrix(VEC3 from, VEC3 to, VEC3 up = Directions::UP);
MAT4 planeRotationMatrix(VEC3 from, VEC3 to);

VEC3 pointInFrame(VEC3 vector, Entity& frame);
VEC3 directionInFrame(VEC3 direction, Entity& frame);
VEC3 directionInFrame(VEC3 direction, QUAT orientation);

std::ostream &operator<<(std::ostream &output, const VEC3& v);
std::ostream &operator<<(std::ostream &output, const QUAT& v);
std::ostream &operator<<(std::ostream &output, const MAT3& v);
std::ostream &operator<<(std::ostream &output, const MAT4& v);

#endif //UTILS_H