#include "entity/Entity.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#include "math/Utils.h"

namespace cuda_render {

Entity::Entity(VEC3 position, VEC3 lookingDirection, VEC3 upDirection, VEC3 scaling) {
    this->m_Position = position;
    this->m_Orientation = utils::toQuat(lookingDirection, upDirection);
    this->m_UpDirection = upDirection;
    this->m_Scaling = scaling;
}

Entity::Entity(VEC3 position, QUAT orientation, VEC3 upDirection, VEC3 scaling) {
    this->m_Position = position;
    this->m_Orientation = orientation;
    this->m_UpDirection = upDirection;
    this->m_Scaling = scaling;
}

MAT4 Entity::getTransform() {
    return glm::scale(glm::translate(glm::mat4_cast(this->m_Orientation), this->m_Position), this->m_Scaling);
}

void Entity::translate(VEC3 vector) {
    moveTo(this->getPosition() + vector);
}

void Entity::scale(VEC3 scaling) {
    scaleTo(this->getScaling() * scaling);
}

void Entity::rotate(FLOAT angle, Entity* reference) {
    if (!reference) reference = this;
    this->m_Orientation = glm::rotate(this->m_Orientation, angle, reference->getUp());
}

void Entity::moveTo(VEC3 point) {
    this->m_Position = point;
}

void Entity::moveTo(Entity& entity) {
    moveTo(entity.getPosition());
}

void Entity::scaleTo(VEC3 scaling) {
    this->m_Scaling = scaling;
}

void Entity::lookTo(VEC3 direction) {
    if (this->m_RotateHead) {
        this->m_Orientation = utils::headRotationQuat(direction, this->getRightwardsDirection(), this->getUp());
    } else {
        this->m_Orientation = utils::toQuat(direction, this->getUp());
    }
}

void Entity::lookAt(VEC3 point) {
    VEC3 direction = point - this->m_Position;
    lookTo(direction);
}

void Entity::lookAt(Entity& entity) {
    lookAt(entity.getPosition());
}

void Entity::move(FLOAT length, Entity* reference) {
    this->move(length, this->getForwardsDirection(), reference);
}

void Entity::move(FLOAT length, VEC3 direction, Entity* reference) {
    this->move(length * glm::normalize(direction), reference);
}

void Entity::move(VEC3 direction, Entity* reference) {
    if (!reference) reference = this;
    moveTo(utils::directionInFrame(direction, *reference));
}

void Entity::look(VEC3 direction, Entity* reference) {
    if (!reference) reference = this;
    lookTo(utils::directionInFrame(direction, *reference));
}

} //namespace cuda_render