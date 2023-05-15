#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include "Starlight.h"
#include <reactphysics3d/reactphysics3d.h>
const float vertices[] = {
                -0.5f, 0.5f, 0.f,//v0
                -0.5f, -0.5f, 0.f,//v1
                0.5f, -0.5f, 0.f,//v2
                0.5f, 0.5f, 0.f,//v3
};
const int indices[] = {
                0,1,3,//top left triangle (v0, v1, v3)
                3,1,2//bottom right triangle (v3, v1, v2)
};



int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Some Game", NULL, NULL);
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

    /**
    * A global physics world needed for interaction 
    */

    rp3d::PhysicsCommon physicsCommon;

    // Create a physics world 
    rp3d::PhysicsWorld* world = physicsCommon.createPhysicsWorld();

    Starlight::Loader loader;
    Starlight::Renderer renderer;
    int length = sizeof(vertices) / sizeof(vertices[0]);
    int indices_length = sizeof(indices) / sizeof(indices[0]);
    Starlight::RawModel model = loader.loadToVAO(length,vertices,indices_length,indices);
    while (!glfwWindowShouldClose(window))
    {
        //input reader
        Starlight::InputManager::Update(window);
        renderer.init();//init renderer
        renderer.render(model);//render
        glfwPollEvents();//looking for events like inputs, resize n stuff
        glfwSwapBuffers(window);//swap buffers on screen
        
    }

    glfwTerminate();
    loader.~Loader();
    return 0;
}