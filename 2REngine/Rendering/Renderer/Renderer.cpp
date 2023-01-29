#include "Renderer.h"

#include "../../External/Glad/glad.h"

void Renderer::RenderLoop()
{
	for (DBufferObject* object : RegisteredObjects)
	{
		_bind_buffer_object(object);
		glDrawElements(GL_TRIANGLES, object->indicesSize, GL_UNSIGNED_INT, (void*)(*object->indices));
		_bind_buffer_object(0);
	}
}

void Renderer::RegisterBufferObject(DBufferObject* object)
{
	RegisteredObjects.push_back(object);
}

void Renderer::UnregisterBufferObject(DBufferObject* object)
{
	for (std::vector<DBufferObject*>::iterator i = RegisteredObjects.begin(); i != RegisteredObjects.end(); i++)
		if (*i == object)
		{
			RegisteredObjects.erase(i);
			break;
		}
}
