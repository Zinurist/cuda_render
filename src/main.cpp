#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "RenderApp.h"

using namespace std;

cuda_render::RenderApp* app = NULL;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (app) {
        app->keyCallback(key, scancode, action, mods);
    }
}

int main(int, char**) {
    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    GLFWwindow* window = glfwCreateWindow(1024, 768, "Cuda Render", NULL, NULL);
    if (!window) {
        cerr << "Failed to open GLFW window." << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    if (glewInit() != GLEW_OK) {
        cerr << "Failed to initialize GLEW" << endl;
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);

    app = new cuda_render::RenderApp(window);
    app->run();
    delete app;

    glfwDestroyWindow(window);
    glfwTerminate();
}
