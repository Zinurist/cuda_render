#ifndef RENDER_APP_H
#define RENDER_APP_H

#include <vector>

#include <GLFW/glfw3.h>

#include "scene/Scene.h"
#include "entity/Entity.h"

class RenderApp {
    public:
        explicit RenderApp(GLFWwindow* window);
        ~RenderApp();

        void run();
        void keyCallback(int key, int scancode, int action, int mods);

        void setActiveScene(int sceneId);
    private: 
        GLFWwindow* m_window = NULL;

        std::vector<Scene> scenes;
        Scene* m_activeScene = NULL;

        bool m_vSyncEnabled = true;

        void buildScenes();
        void toggleVSync();

};

#endif //RENDER_APP_H