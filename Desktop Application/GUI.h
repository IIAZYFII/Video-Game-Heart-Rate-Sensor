#ifndef GUI_H
#define GUI_H
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
class GUI
{

public:
    GUI();
    ~GUI();
    void NewFrame();
    void Init(GLFWwindow * window, const char* glsl_version);
    virtual void Update();
    void Render();
    void Shutdown();
};
#endif