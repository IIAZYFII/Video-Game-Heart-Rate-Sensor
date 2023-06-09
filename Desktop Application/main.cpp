#include "server.h"
#include "GUI.h"

int main()
{
    const char *glsl_version = "#version 130";

    if (!glfwInit())
    {
        return 1;
    }

    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(1280, 720, "Example", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Setup Platform/Renderer backends
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw("Unable to context with OpenGL");
    }

    int screen_width, screen_height;
    glfwGetFramebufferSize(window, &screen_width, &screen_height);
    glViewport(0, 0, screen_width, screen_height);

    GUI gui = GUI();
    gui.Init(window, glsl_version);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        gui.NewFrame();
        gui.Update();
        gui.Render(window, screen_width, screen_height);
        glfwSwapBuffers(window);
    }

    gui.Shutdown(window);

    // Server server;
    // server.run();

    return 0;
}