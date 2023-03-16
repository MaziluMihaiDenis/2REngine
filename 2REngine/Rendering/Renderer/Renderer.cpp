#include "Renderer.h"

#include "../../External/Glad/glad.h"

void Renderer::RenderLoop()
{
	for (DisplayObject* object : RegisteredObjects)
	{
		glDrawElements(GL_TRIANGLES, object->indicesSize, GL_UNSIGNED_INT, (void*)(*object->indices));
	}
}

void Renderer::RegisterDisplayObject(DisplayObject* object)
{
	RegisteredObjects.push_back(object);
}

void Renderer::UnregisterDisplayObject(DisplayObject* object)
{
	for (std::vector<DisplayObject*>::iterator i = RegisteredObjects.begin(); i != RegisteredObjects.end(); i++)
		if (*i == object)
		{
			RegisteredObjects.erase(i);
			break;
		}
}
