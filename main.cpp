#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include "Starlight.h"

const float vertices[] = {
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
        //input reader
        Starlight::InputManager::processInput(window);
        renderer.init();//init renderer
        renderer.render(model);//render
        glfwPollEvents();//looking for events like inputs, resize n stuff
        glfwSwapBuffers(window);//swap buffers on screen
        
    }

    glfwTerminate();
    loader.~Loader();
    return 0;
}