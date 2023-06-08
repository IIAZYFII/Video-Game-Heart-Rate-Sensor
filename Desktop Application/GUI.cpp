#include "GUI.h"
GUI::GUI(){}
GUI::~GUI(){}

void GUI::Init(GLFWwindow * window, const char* glsl_version)
{
  
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

     ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void GUI::NewFrame() 
{
    
}

 void GUI::Update()
{

}
void GUI::Render(){}
void GUI::Shutdown(){}
