#include "GUI.h"
GUI::GUI() {}
GUI::~GUI() {}

void GUI::Init(GLFWwindow *window, const char *glsl_version)
{

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImGui::StyleColorsLight();
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.29f, 0.29f, 0.32f, 1.0f));
}

void GUI::NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void GUI::Update()
{
    ImGui::Begin("Placholder name", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    ImGui::Indent();
    const char *ip_addresses[] = {"192.168.0.1", "192.168.0.13"};
    static int current_item = 0;

    ImGui::SetNextItemWidth(150);

    ImGui::Combo("##", &current_item, ip_addresses, IM_ARRAYSIZE(ip_addresses));
    ImGui::End();
}

void GUI::Render(GLFWwindow *window)
{

    int screen_width, screen_height;
    glfwGetFramebufferSize(window, &screen_width, &screen_height);
    glViewport(0, 0, screen_width, screen_height);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
void GUI::Shutdown(GLFWwindow *window)
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}