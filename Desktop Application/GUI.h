#include <imgui.h>
class GUI
{

public:
    virtual void Init();
    virtual void Update();
    void Render();
    void Shutdown();
};