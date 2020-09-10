#ifndef TYPES_H
#define TYPES_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

typedef float FLOAT;
typedef glm::vec3 VEC3;
typedef glm::quat QUAT;
typedef glm::mat3 MAT3;
typedef glm::mat4 MAT4;

const QUAT DEFAULT_QUAT = QUAT(1.0, 0.0, 0.0, 0.0);

namespace Directions {
    const VEC3 NORTH = VEC3(0.0, 0.0, -1.0);
    const VEC3 EAST = VEC3(1.0, 0.0, 0.0);
    const VEC3 SOUTH = VEC3(0.0, 0.0, 1.0);
    const VEC3 WEST = VEC3(-1.0, 0.0, 0.0);
    const VEC3 SKY = VEC3(0.0, 1.0, 0.0);
    const VEC3 GROUND = VEC3(0.0, -1.0, 0.0);

    const VEC3 FORWARD = NORTH;
    const VEC3 RIGHT = EAST;
    const VEC3 BACKWARD = SOUTH;
    const VEC3 LEFT = WEST;
    const VEC3 UP = SKY;
    const VEC3 DOWN = GROUND;
};

#endif //TYPES_H