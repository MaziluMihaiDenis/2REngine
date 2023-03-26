#include "2relibrary.h"
#include "Core/Engine/WindowManager.h"
#include "Core/Engine/Engine.h"
#include "External/Glad/glad.h"
#include "Core/Types/Debug/debug.h"
#include "Core/Engine/Classes/Component/DisplayComponent.h"
#include "Rendering/Renderer/Renderer.h"
#include <Constants.h>

int main()
{
    float delta, startTime; 

    REWindow* mainWindow;
    int winWidth, winHeight;

    re_init();
    Engine::GetInstance()->Begin();

    mainWindow = WindowManager::GetInstance()->GetWindow(0);
    winWidth = mainWindow->settings->width;
    winHeight = mainWindow->settings->height;

    re_set_context_current(mainWindow);
    glViewport(0, 0, winWidth, winHeight); 

    PRINT(0, "%s", glGetString(GL_VERSION));

    delta = 0.0;

    DisplayComponent* dc = new DisplayComponent();
    Renderer::GetInstance()->RegisterDisplayObject(dc);
    dc->SetTexture("2REngine/SwagGorilla.png");

    while (mainWindow->running)
    {
        startTime = re_get_time_ms();

        re_set_window_color(NICE_COLOR);
        re_poll_events();

        Engine::GetInstance()->Loop(delta);

        re_swap_buffers(mainWindow);

        delta = 1.f * (re_get_time_ms() - startTime) / re_get_time_frequency();
    }

    re_terminate();

    return 0;
}