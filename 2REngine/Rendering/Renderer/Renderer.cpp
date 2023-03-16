#include "Renderer.h"

#include "../../External/Glad/glad.h"

void Renderer::RenderLoop()
{
	for (DisplayComponent* object : RegisteredObjects)
		object->Render();
}

void Renderer::RegisterDisplayObject(DisplayComponent* object)
{
	RegisteredObjects.push_back(object);
}

void Renderer::UnregisterDisplayObject(DisplayComponent* object)
{
	for (std::vector<DisplayComponent*>::iterator i = RegisteredObjects.begin(); i != RegisteredObjects.end(); i++)
		if (*i == object)
		{
			RegisteredObjects.erase(i);
			break;
		}
}

Renderer* Renderer::GetInstance()
{
	if (Instance == nullptr)
		Instance = new Renderer();
	return Instance;
}
