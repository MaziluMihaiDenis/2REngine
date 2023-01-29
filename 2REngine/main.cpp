#include "Core/Engine/WindowManager.h"
#include "Core/2relibrary.h"
#include "External/Glad/glad.h"
#include <stdio.h>

int main()
{
    re_init();

    // Initialize Window
    REWindow* mainWindow;
    int winWidth, winHeight;

    WindowManager::GetWindowManager()->InitWindow();
    mainWindow = WindowManager::GetWindowManager()->GetWindow(0);
    winWidth = mainWindow->settings->size.x;
    winHeight = mainWindow->settings->size.y;

    // Initialize GL
    re_set_context_current(mainWindow);
    if (!gladLoadGL()) {
        if (DEBUG_MODE_ENABLED)
            printf("glad init error");
        return 1;
    }
    glViewport(0, 0, winWidth, winHeight); // Error here

    while (mainWindow->running)
    {
        re_poll_events();

        re_swap_buffers(mainWindow);
    }

    re_terminate();

    return 0;
}