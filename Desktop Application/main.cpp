#include "imgui.h"
#include "server.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"

int main()
{

    Server server;
    server.run();

    return 0;
}