#include "entity/Entity.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#include "math/Utils.h"

Entity::Entity(VEC3 position, VEC3 forwardsDirection, VEC3 upwardsDirection, VEC3 scaling) {
    this->position = position;
    this->lookingDirection = VEC3(1.0, 0.0, 0.0);
    //TODO
    this->orientation = QUAT();
    this->scaling = scaling;
}

Entity::Entity(VEC3 position, VEC3 lookingDirection, QUAT orientation, VEC3 scaling) {
    this->position = position;
    this->lookingDirection = lookingDirection;
    this->scaling = scaling;
    this->orientation = orientation;
}

MAT4 Entity::getTransform() {
    return glm::scale(glm::translate(glm::mat4_cast(this->orientation), this->position), this->scaling);
}

void Entity::translate(VEC3 vector) {
    moveTo(this->position + vector);
}

void Entity::scale(VEC3 scaling) {
    scaleTo(this->scaling * scaling);
}

void Entity::rotate(FLOAT angle, Entity* reference) {
    if (!reference) reference = this;
    this->orientation = glm::rotate(this->orientation, angle, reference->lookingDirection);
}

void Entity::moveTo(VEC3 point) {
    this->position = point;
}

void Entity::moveTo(Entity& entity) {
    moveTo(entity.position);
}

void Entity::scaleTo(VEC3 scaling) {
    this->scaling = scaling;
}

void Entity::lookTo(VEC3 direction) {
    MAT4 rot = this->rotateHead ? headRotationMatrix(this->lookingDirection, direction) : planeRotationMatrix(this->lookingDirection, direction);
    this->orientation = glm::quat_cast(rot) * this->orientation;
    this->lookingDirection = direction;
}

void Entity::lookAt(VEC3 point) {
    VEC3 direction = point - this->position;
    lookTo(direction);
}

void Entity::lookAt(Entity& entity) {
    lookAt(entity.position);
}

void Entity::move(FLOAT length, Entity* reference) {
    if (!reference) reference = this;
    move(length * glm::normalize(reference->lookingDirection));
}

void Entity::move(FLOAT length, VEC3 direction, Entity* reference) {
    if (!reference) reference = this;
    move(length * glm::normalize(directionInFrame(direction, *reference)));
}

void Entity::move(VEC3 direction, Entity* reference) {
    if (!reference) reference = this;
    moveTo(directionInFrame(direction, *reference));
}

void Entity::look(VEC3 direction, Entity* reference) {
    if (!reference) reference = this;
    lookTo(directionInFrame(direction, *reference));
}