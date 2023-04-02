#include "Engine.h"
#include <Graphics/Graphics.h>

void Engine::Init()
{
}

void Engine::Loop(float deltaTime)
{
	Graphics::GetInstance()->Loop();
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
