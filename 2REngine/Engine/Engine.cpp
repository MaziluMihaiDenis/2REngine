#include "Engine.h"
#include <Graphics/Graphics.h>
#include <Application/Application.h>

void Engine::Init()
{
}

void Engine::Loop(float deltaTime)
{
	Application::GetInstance()->PreLoop();
	Graphics::GetInstance()->Loop();
	Application::GetInstance()->Loop();
}

void Engine::End()
{
}

Engine* Engine::GetInstance()
{
	if (!Instance)
		Instance = new Engine();
	return Instance;
}
