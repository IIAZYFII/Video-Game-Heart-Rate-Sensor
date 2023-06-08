#include "server.h"
#include "GUI.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{

    if (!glfwInit())
    {
        return 1;
    }

    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(1280, 720, "Example", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle &style = ImGui::GetStyle();

    // Setup Platform/Renderer backends
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw("Unable to context with OpenGL");
    }

    int screen_width, screen_height;
	glfwGetFramebufferSize(window, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);


    //Server server;
   // server.run();

    return 0;
}