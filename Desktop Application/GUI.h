#ifndef GUI_H
#define GUI_H
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include "server.h"
class GUI
{

public:
    GUI();
    ~GUI();
    void NewFrame();
    void Init(GLFWwindow *window, const char *glsl_version);
    void Update();
    void Update(bool &s_started);
    void Render(GLFWwindow *window);
    void Shutdown(GLFWwindow *window);
    void loadImage 
};
#endif