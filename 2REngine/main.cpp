#include "2relibrary.h"
#include "Core/Engine/WindowManager.h"
#include "Core/Engine/Engine.h"
#include "External/Glad/glad.h"
#include "Core/Types/Debug/debug.h"

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
    if (!gladLoadGL()) 
    {
        if (DEBUG_MODE_ENABLED)
            PRINT(ESEVERITY::DEFAULT, "%s", "GL couldn't load!");
        return 1;
    }
    glViewport(0, 0, winWidth, winHeight); 

    delta = 0.0;

    while (mainWindow->running)
    {
        startTime = re_get_time_ms();

        re_poll_events();

        Engine::GetInstance()->Loop(delta);

        re_swap_buffers(mainWindow);

        delta = 1.f * (re_get_time_ms() - startTime) / re_get_time_frequency();
    }

    re_terminate();

    return 0;
}