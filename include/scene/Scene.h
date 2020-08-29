#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "camera/Camera.h"

class Scene {
    public:
        void update(double dt);

        void enter();
        void exit();

        void render();

        void setActiveCamera(int cameraId);

    private:
        std::vector<Camera> cameras;
        Camera* m_activeCamera = NULL;

};

#endif //SCENE_H