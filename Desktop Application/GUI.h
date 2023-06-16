#ifndef GUI_H
#define GUI_H

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "server.h"

class GUI
{
private:
    ImFont *segoeui_font = NULL;
    ImFont *inter_bold_font = NULL;

public:
    GUI();
    ~GUI();
    void NewFrame();
    void Init(GLFWwindow *window, const char *glsl_version);
    void Update(GLuint heart_texture, int heart_height, int heart_width, int &bpm);
    void Update(bool &s_started);
    void Render(GLFWwindow *window);
    void Shutdown(GLFWwindow *window);
    bool loadImage(const char *filename, GLuint &out_texture, int &out_width, int &out_height);
};
#endif