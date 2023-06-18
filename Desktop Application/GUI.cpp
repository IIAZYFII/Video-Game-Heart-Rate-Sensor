#include "GUI.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
GUI::GUI() {}
GUI::~GUI() {}

void GUI::Init(GLFWwindow *window, const char *glsl_version)
{

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    segoeui_font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
    inter_bold_font = io.Fonts->AddFontFromFileTTF("Assets\\Fonts\\Inter-ExtraBold.ttf", 50.0f);

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

void GUI::Update(GLuint heart_texture, int heart_height, int heart_width, int &bpm, bool &s_started)
{
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));

    ImGui::Begin("Placholder name", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    ImGui::Indent();

    ImGui::Image((void *)(intptr_t)heart_texture, ImVec2(heart_width, heart_height));

    ImGui::Indent();
    ImGui::Indent();
    ImGui::SameLine();

    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::PushFont(inter_bold_font);

    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));

    ImGui::Text(std::to_string(bpm).c_str());

    ImGui::SameLine();
    ImGui::Text("BPM");
    ImGui::PopFont();
    ImGui::PopStyleColor();

    if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Escape)))
    {
        s_started = false;
        std::cout << "test \n";
    }

    ImGui::End();

    ImGui::PopStyleColor();
}

void GUI::Update(bool &s_started, int &s_port)
{
    ImGui::Begin("Placholder name", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    ImGui::Indent();
    const char *ip_addresses[] = {"192.168.0.1", "192.168.0.13"};
    static int current_item = 0;

    ImGui::SetNextItemWidth(150);
    ImGui::Combo("##combo", &current_item, ip_addresses, IM_ARRAYSIZE(ip_addresses));

    ImGui::SameLine();
    ImGui::SetNextItemWidth(50);

    static char portTextBuffer[5] = "9002";
    ImGui::InputText("##Port", portTextBuffer, IM_ARRAYSIZE(portTextBuffer), ImGuiInputTextFlags_CharsDecimal);

    ImGui::SameLine();
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
    ImGui::Text("Port");
    ImGui::SameLine();
    if (ImGui::Button("Start"))
    {

        s_port = atoi(portTextBuffer);
        s_started = true;
    }
    ImGui::PopStyleColor();

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

bool GUI::loadImage(const char *filename, GLuint &out_texture, int &out_width, int &out_height)
{

    int width = 0;
    int height = 0;

    unsigned char *image_data = stbi_load(filename, &width, &height, NULL, 4);

    if (image_data == NULL)
    {
        return false;
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    out_texture = texture;
    out_width = width;
    out_height = height;

    return true;
}