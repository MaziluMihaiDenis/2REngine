#include "2relibrary.h"
#include "Core/Engine/WindowManager.h"
#include "Core/Engine/Engine.h"
#include "External/Glad/glad.h"
#include <stdio.h>

int main()
{
    REWindow* mainWindow;
    int winWidth, winHeight;

    re_init();
    Engine::GetInstance()->Begin();

    mainWindow = WindowManager::GetInstance()->GetWindow(0);
    winWidth = mainWindow->settings->width;
    winHeight = mainWindow->settings->height;

    re_set_context_current(mainWindow);
    if (!gladLoadGL()) {
        if (DEBUG_MODE_ENABLED)
            printf("glad init error");
        return 1;
    }
    glViewport(0, 0, winWidth, winHeight); 

    while (mainWindow->running)
    {
        re_poll_events();

        re_swap_buffers(mainWindow);
    }

    re_terminate();

    return 0;
}