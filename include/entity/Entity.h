#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "math/Types.h"
#include "math/Utils.h"

namespace cuda_render {

class Entity {
    public:
        Entity() : Entity(VEC3(0.0)) {}
        Entity(VEC3 position) : Entity(position, DEFAULT_QUAT) {}
        Entity(VEC3 position, QUAT orientation) : Entity(position, orientation, Directions::UP) {}
        Entity(VEC3 position, QUAT orientation, VEC3 upDirection) : Entity(position, orientation, upDirection, VEC3(1.0)) {}
        Entity(VEC3 position, QUAT orientation, VEC3 upDirection, VEC3 scaling);

        Entity(VEC3 position, VEC3 lookingDirection) : Entity(position, lookingDirection, Directions::UP) {}
        Entity(VEC3 position, VEC3 lookingDirection, VEC3 upDirection) : Entity(position, lookingDirection, upDirection, VEC3(1.0)) {}
        Entity(VEC3 position, VEC3 lookingDirection, VEC3 upDirection, VEC3 scaling);


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

        void toggleRotateHead() { m_RotateHead = !m_RotateHead; }
        void setRotateHead(bool rotateHead) { this->m_RotateHead = rotateHead; }

        VEC3 getPosition() { return m_Position; }
        VEC3 getScaling() { return m_Scaling; }
        VEC3 getUp() { return m_UpDirection; }
        QUAT getOrientation() { return m_Orientation; }

        VEC3 getForwardsDirection() { return utils::xAxisOf(m_Orientation); }
        VEC3 getUpwardsDirection() { return utils::yAxisOf(m_Orientation); }
        VEC3 getRightwardsDirection() { return utils::zAxisOf(m_Orientation); }
        VEC3 getBackwardsDirection() { return -getForwardsDirection(); }
        VEC3 getDownwardsDirection() { return -getUpwardsDirection(); }
        VEC3 getLeftwardsDirection() { return -getRightwardsDirection(); }

    protected:
        VEC3 m_Position;
        VEC3 m_Scaling;
        VEC3 m_UpDirection;
        QUAT m_Orientation;

        bool m_RotateHead;

};

} //namespace cuda_render

#endif //ENTITY_H