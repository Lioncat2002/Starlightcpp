#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include "Engine/Renderer/Loader.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Models/RawModel.h"

float vertices[] = {
    -0.5f, 0.5f, 0.f,
    -0.5f, -0.5f, 0.f,
    0.5f, -0.5f, 0.f,
    0.5f, -0.5f, 0.f,
    0.5f, 0.5f, 0.f,
    -0.5f, 0.5f, 0.f
};


void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    Starlight::Loader loader;
    Starlight::Renderer renderer;
    int length = sizeof(vertices) / sizeof(vertices[0]);
    Starlight::RawModel model = loader.loadToVAO(length,vertices);
    while (!glfwWindowShouldClose(window))
    {
        renderer.init();
        processInput(window);
        
        renderer.render(model);
        glfwPollEvents();
        glfwSwapBuffers(window);
        
    }

    glfwTerminate();
    loader.~Loader();
    return 0;
}