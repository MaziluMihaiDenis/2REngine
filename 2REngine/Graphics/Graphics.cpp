#include "Graphics.h"
#include <External/Glad/glad.h>
#include <External/stb_image/stb_image.h>
#include <Application/Application.h>
extern "C"
{
#include <Debug/debug.h>
}

void Graphics::Init()
{
	stbi_set_flip_vertically_on_load(1);

	REWindow* window = Application::GetInstance()->GetWindowInstance();
	glViewport(0, 0, window->settings->width, window->settings->height);
}

void Graphics::Loop()
{
	for (SpriteComponent* object : RegisteredObjects)
		object->Render();
}

void Graphics::RegisterDisplayObject(SpriteComponent* object)
{
	RegisteredObjects.push_back(object);
}

void Graphics::UnregisterDisplayObject(SpriteComponent* object)
{
	for (std::vector<SpriteComponent*>::iterator i = RegisteredObjects.begin(); i != RegisteredObjects.end(); i++)
		if (*i == object)
		{
			RegisteredObjects.erase(i);
			break;
		}
}

Graphics* Graphics::GetInstance()
{
	if (Instance == nullptr)
		Instance = new Graphics();
	return Instance;
}
