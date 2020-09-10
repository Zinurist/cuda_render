#include "math/Utils.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "entity/Entity.h"

MAT4 headRotationMatrix(VEC3 from, VEC3 to, VEC3 up) {
    from = glm::normalize(from);
    to = glm::normalize(to);
    up = glm::normalize(up);
    MAT4 rot(1.0);

    VEC3 normalFrom = glm::cross(from, up);
    FLOAT angleFrom = glm::acos(glm::dot(from, up));
    VEC3 normalTo = glm::cross(up, to);
    FLOAT angleTo = glm::acos(glm::dot(up, to));

    rot = glm::rotate(rot, angleFrom, normalFrom);
    rot = glm::rotate(rot, angleTo, normalTo);

    VEC3 fromOnTo = MAT3(rot) * from;
    VEC3 normal = glm::cross(fromOnTo, to);
    FLOAT angle = glm::acos(glm::dot(fromOnTo, to));
    rot = glm::rotate(rot, angle, normal);
    return rot;
}

MAT4 planeRotationMatrix(VEC3 from, VEC3 to) {
    from = glm::normalize(from);
    to = glm::normalize(to);
    VEC3 normal = glm::cross(from, to);
    FLOAT angle = glm::acos(glm::dot(from, to));
    return glm::rotate(MAT4(1.0), angle, normal);
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