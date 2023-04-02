#include <Graphics/Graphics.h>
#include <Application/Application.h>
#include <Engine/Engine.h>
#include <Debug/debug.h>
#include <External/Glad/glad.h>
#include <Application/Core/internal.h>
#include <Resources/TextureImporter.h>
#include "2relibrary.h"

int main()
{
    float delta, startTime; 

    Engine::GetInstance()->Init();
    Application::GetInstance()->Init();
    Graphics::GetInstance()->Init();
    TextureImporter::Init();

    Application::GetInstance()->SetBackgroundColor(NICE_COLOR);

    delta = 0.0;

    PRINT(0, "%s", glGetString(GL_VERSION));

    while (Application::GetInstance()->IsRunning())
    {
        startTime = re_get_time_ms();

        Engine::GetInstance()->Loop(delta);
        Application::GetInstance()->Loop();

        delta = 1.f * (re_get_time_ms() - startTime) / re_get_time_frequency();
    }

    re_terminate();

    return 0;
}