#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include <glm/glm.hpp>

#include "math/Direction.h"

class Entity {
    public:


        virtual void render() = 0;

    protected:
        glm::vec3 position;
        glm::vec3 scale;
        glm::vec3 rotation;
        glm::vec3 direction = Directions::EAST;

};

#endif //ENTITY_H