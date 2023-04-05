#include "2relibrary.h"

#include <Graphics/Graphics.h>
#include <Application/Application.h>
#include <Engine/Engine.h>
#include <Application/Core/internal.h>
#include <Resources/TextureImporter.h>
#include <Engine/Structs/Transformation2D.h>

void key_callback(int key, int state)
{
    if (key == RE_KEY_SPACE && state == RE_KEY_PRESS)
    {
        exit(0);
    }
}

int main()
{
    float delta;
    int startTime; 

    re_init();
    Engine::GetInstance()->Init();
    Application::GetInstance()->Init();
    Graphics::GetInstance()->Init();
    TextureImporter::Init();

    re_set_key_callback(&key_callback);

    Application::GetInstance()->SetBackgroundColor(NICE_COLOR);

    PRINT(0, "%s", glGetString(GL_VERSION));

    delta = 0.f;

    Transformation2D trs;
    trs.Position = Vector2D(0, 0);
    trs.Size = Vector2D(300, 300);
    trs.Rotation = 0.f;

    DisplayComponent* dc = new DisplayComponent();
    Graphics::GetInstance()->RegisterDisplayObject(dc);
    dc->BufferData(trs);
    dc->SetColor(1, 1, 1);
    dc->SetProjection(ortho(0, 0, 1920, 1080));

    while (Application::GetInstance()->IsRunning())
    {
        startTime = re_get_time_ms();

        trs.Rotation += delta;
        dc->BufferData(trs);

        Engine::GetInstance()->Loop(delta);

        delta = 1.f * (re_get_time_ms() - startTime) / re_get_time_frequency();
    }

    re_terminate();

    return 0;
}