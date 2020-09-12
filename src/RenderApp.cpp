#include "RenderApp.h"

#include <iostream>

namespace cuda_render {

RenderApp::RenderApp(GLFWwindow* window) {
    this->m_window = window;
    this->buildScenes();
}

RenderApp::~RenderApp() {
}


void RenderApp::buildScenes() {
    
}

void RenderApp::run() {
    GLFWwindow* window = this->m_window;

    double startTime = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        double endTime = glfwGetTime();
        double dt = endTime - startTime;
        startTime = endTime;

        if (this->m_activeScene) {
            this->m_activeScene->update(dt);
            this->m_activeScene->render();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void RenderApp::keyCallback(int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->m_window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_V && action == GLFW_PRESS) {
        this->toggleVSync();
    }

    if (key >= GLFW_KEY_0 && key <= GLFW_KEY_9 && action == GLFW_PRESS) {
        int id = key - GLFW_KEY_0;
        if (mods & GLFW_MOD_CONTROL) {
            this->setActiveScene(id);
        } else {
            if (this->m_activeScene) this->m_activeScene->setActiveCamera(id);
        }
    }
}


void RenderApp::setActiveScene(int sceneId) {
    if (sceneId >= 0 && sceneId < this->scenes.size()) {
        this->m_activeScene = &(this->scenes[sceneId]);
        std::cout << "Activating scene " << sceneId << std::endl;
    } else {
        this->m_activeScene = NULL;
        std::cout << "No such scene" << std::endl;
    }
}

void RenderApp::toggleVSync() {
    this->m_vSyncEnabled = !this->m_vSyncEnabled;
    glfwSwapInterval(this->m_vSyncEnabled ? 1 : 0);
}

} //namespace cuda_render