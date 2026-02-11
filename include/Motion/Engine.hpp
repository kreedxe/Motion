
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <backend/imgui_impl_glfw.h>
#include <backend/imgui_impl_opengl3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <cmath>

#include <stb_image.h>


class Engine 
{

private:
    float currentTime = 0.0f;
    float frameTime = 0.0f;
    float deltaTime = 0.0f;
    float lastTime = 0.0f;
    float fps = 0.0f;

public:
    int SCR_WIDTH = 1200;
    int SCR_HEIGHT = 800;
    const char* SCR_TITLE = "Motion | OpenGL 4.6 + GLFW";

    GLFWwindow* window;

    Engine();
    ~Engine();

    int initGLFW();

    void update();
    void destroy();
};