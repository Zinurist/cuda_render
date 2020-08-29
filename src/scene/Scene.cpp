#include "scene/Scene.h"

#include <iostream>

void Scene::update(double dt) {
    
}

void Scene::enter() {
    
}

void Scene::exit() {
    
}

void Scene::setActiveCamera(int cameraId) {
    if (cameraId >= 0 && cameraId < this->cameras.size()) {
        this->m_activeCamera = &(this->cameras[cameraId]);
        std::cout << "Activating camera " << cameraId << std::endl;
    } else {
        this->m_activeCamera = NULL;
        std::cout << "No such camera" << std::endl;
    }
}

void Scene::render() {
    if (this->m_activeCamera) {
        this->m_activeCamera->render();
    }
}
