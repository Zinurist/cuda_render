#ifndef CAMERA_H
#define CAMERA_H

#include "entity/Entity.h"

namespace cuda_render {

class Camera: public Entity {
    public:
        void render();

};

} //namespace cuda_render

#endif //CAMERA_H