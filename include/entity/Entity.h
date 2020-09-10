#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "math/Types.h"
#include "math/Utils.h"

class Entity {
    public:
        Entity() : Entity(VEC3(0.0), Directions::SOUTH, DEFAULT_QUAT, VEC3(1.0)) {}
        Entity(VEC3 position) : Entity(position, Directions::SOUTH, DEFAULT_QUAT, VEC3(1.0)) {}
        Entity(VEC3 position, QUAT orientation) : Entity(position, directionInFrame(Directions::SOUTH, orientation), orientation, VEC3(1.0)) {}
        Entity(VEC3 position, VEC3 lookingDirection) : Entity(position, lookingDirection, DEFAULT_QUAT, VEC3(1.0)) {}
        Entity(VEC3 position, VEC3 lookingDirection, QUAT orientation) : Entity(position, lookingDirection, orientation, VEC3(1.0)) {}
        Entity(VEC3 position, VEC3 forwardsDirection, VEC3 upwardsDirection) : Entity(position, forwardsDirection, upwardsDirection, VEC3(1.0)) {}
        
        Entity(VEC3 position, VEC3 forwardsDirection, VEC3 upwardsDirection, VEC3 scaling);
        Entity(VEC3 position, VEC3 lookingDirection, QUAT orientation, VEC3 scaling);

        virtual void render() = 0;

        MAT4 getTransform();

        void translate(VEC3 vector);
        void scale(VEC3 scaling);
        void rotate(FLOAT angle, Entity* reference = nullptr);

        void moveTo(VEC3 point);
        void moveTo(Entity& entity);
        void scaleTo(VEC3 scaling);
        void lookTo(VEC3 direction);
        void lookAt(VEC3 point);
        void lookAt(Entity& entity);

        void move(FLOAT length, Entity* reference = nullptr);
        void move(FLOAT length, VEC3 direction, Entity* reference = nullptr);
        void move(VEC3 direction, Entity* reference = nullptr);
        void look(VEC3 direction, Entity* reference = nullptr);

        void toggleRotateHead() { rotateHead = !rotateHead; }
        void setRotateHead(bool rotateHead) { this->rotateHead = rotateHead; }

        VEC3 getPosition() { return position; }
        QUAT getOrientation() { return orientation; }

    protected:
        VEC3 position;
        VEC3 scaling;
        VEC3 lookingDirection;
        QUAT orientation;

        bool rotateHead;

};

#endif //ENTITY_H