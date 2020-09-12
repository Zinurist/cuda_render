#include "math/Utils.h"

#include <cmath>
#include <random>

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "entity/Entity.h"

namespace cuda_render {
namespace utils {

std::default_random_engine generator;
std::uniform_real_distribution<FLOAT> distribution(-1.0, 1.0);
FLOAT rand() { 
    return distribution(generator); 
}

VEC3 xAxisOf(QUAT q) {
    return glm::mat3_cast(q)[0];
}

VEC3 yAxisOf(QUAT q) {
    return glm::mat3_cast(q)[1];
}

VEC3 zAxisOf(QUAT q) {
    return glm::mat3_cast(q)[2];
}

QUAT toQuat(VEC3 xAxis, VEC3 yAxis) {
    return toQuat(xAxis, yAxis, glm::cross(xAxis, yAxis));
}

QUAT toQuat(VEC3 xAxis, VEC3 yAxis, VEC3 zAxis) {
    MAT3 rot;
    rot[0] = glm::normalize(xAxis);
    rot[1] = glm::normalize(yAxis);
    rot[2] = glm::normalize(zAxis);
    return glm::quat_cast(rot);
}

VEC4 toVec4(QUAT q) {
    return VEC4(q[0], q[1], q[2], q[3]);
}

VEC3 randomVec3() {
    return VEC3(utils::rand(), utils::rand(), utils::rand());
}

MAT3 randomRot() {
    return MAT3(glm::rotate(MAT4(1.0), utils::rand()*glm::pi<FLOAT>(), randomVec3()));
}

QUAT headRotationQuat(VEC3 lookingDirection, VEC3 currentRightDirection, VEC3 upDirection) {
    lookingDirection = glm::normalize(lookingDirection);
    upDirection = glm::normalize(upDirection);
    VEC3 rightDirection = glm::cross(lookingDirection, upDirection);
    if (glm::length(rightDirection) < EPS) {
        rightDirection = glm::normalize(currentRightDirection);
    }
    VEC3 newUpDirection = glm::cross(rightDirection, lookingDirection);
    return toQuat(lookingDirection, newUpDirection);
}

VEC3 pointInFrame(VEC3 point, Entity& frame) {
    return directionInFrame(point - frame.getPosition(), frame.getOrientation());
}

VEC3 directionInFrame(VEC3 direction, Entity& frame) {
    return directionInFrame(direction, frame.getOrientation());
}

VEC3 directionInFrame(VEC3 direction, QUAT orientation) {
    return glm::mat3_cast(glm::inverse(orientation)) * direction;
}

std::ostream &operator<<(std::ostream &output, const VEC3& v) {
    output << "Vec3(x=" << v[0] << ", y=" << v[1] << ", z=" << v[2] << ")" << std::endl;
}

std::ostream &operator<<(std::ostream &output, const QUAT& q) {
    output << "Quat(x=" << q[0] << ", y=" << q[1] << ", z=" << q[2] << ", w=" << q[3] << ")" << std::endl;
}

std::ostream &operator<<(std::ostream &output, const MAT3& m) {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            output << m[y][x] << " ";
        }
        output << std::endl;
    }
}

std::ostream &operator<<(std::ostream &output, const MAT4& m) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            output << m[y][x] << " ";
        }
        output << std::endl;
    }
}

bool floatEqual(FLOAT f1, FLOAT f2) {
    return fabs(f1-f2) < EPS;
}

bool floatEqual(VEC3 v1, VEC3 v2) {
    return glm::distance(v1, v2) < EPS;
}

bool floatEqual(QUAT q1, QUAT q2) {
    return glm::distance(toVec4(q1), toVec4(q2)) < EPS;
}

} //namespace utils
} //namespace cuda_render