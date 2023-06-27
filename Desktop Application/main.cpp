#include "GUI.h"
#include <thread>
#include <stdlib.h>
static bool s_started = false;
static int s_port = 9002;
static int bpm = 0;

void startServer(Server &server)
{
    while (1)
    {
        if (s_started == true)
        {
            server.run(bpm, s_port);
        }
    }
}

int startGUI(Server &server)
{
    const char *glsl_version = "#version 130";

    if (!glfwInit())
    {
        return 1;
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(400, 100, "StreamerKardiogramm", nullptr, nullptr);
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

    int heart_width = 0;
    int heart_height = 0;
    GLuint heart_texture = 0;

    const char *filename = "Assets/Images/red-heart-icon.png";

    bool ret = gui.loadImage(filename, heart_texture, heart_width, heart_height);
    IM_ASSERT(ret);

    while (!glfwWindowShouldClose(window))
    {

        glfwPollEvents();
        gui.NewFrame();
        if (s_started == true)
        {
            gui.Update(heart_texture, 50, 50, bpm, s_started);
        }
        else
        {
            gui.Update(s_started, s_port);
            if (server.isOpen() == true && s_started == false)
            {

                server.stop();
            }
        }

        gui.Render(window);
        glfwSwapBuffers(window);
    }

    gui.Shutdown(window);
    return 0;
}

int main()
{
    Server server;
    std::thread guiWorker(startGUI, std::ref(server));
    std::thread serverWorker(startServer, std::ref(server));
    serverWorker.join();
    guiWorker.join();
    return 0;
}

