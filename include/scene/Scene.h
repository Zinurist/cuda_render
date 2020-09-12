#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "camera/Camera.h"

namespace cuda_render {

class Scene {
    public:
        void update(double dt);

        void enter();
        void exit();

        void render();

        void setActiveCamera(int cameraId);

    private:
        std::vector<Camera> cameras;
        Camera* m_activeCamera = nullptr;

};

} //namespace cuda_render

#endif //SCENE_H