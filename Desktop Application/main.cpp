#include "GUI.h"
#include <thread>

static bool s_started = false;
static bool s_running = false;

void startServer()
{
    Server server;
    server.run();
}

int startGUI()
{
    const char *glsl_version = "#version 130";

    if (!glfwInit())
    {
        return 1;
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(400, 250, "Example", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Setup Platform/Renderer backends
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw("Unable to context with OpenGL");
    }

    GUI gui = GUI();

    gui.Init(window, glsl_version);

    while (!glfwWindowShouldClose(window))
    {

        glfwPollEvents();
        gui.NewFrame();
        gui.Update(s_started);
        gui.Render(window);
        glfwSwapBuffers(window);
    }

    gui.Shutdown(window);
    return 0;
}

int main()
{

    std::thread guiWorker(startGUI);
    while (s_started == false)
    {
        std::cout << "waiting...";
    }
    std::thread serverWorker(startServer);
    serverWorker.join();
    guiWorker.join();

    return 0;
}