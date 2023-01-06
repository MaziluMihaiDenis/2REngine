#include "BufferObject.h"
#include "../../Core/2relibrary.h"
#include <glad/glad.h>

DBufferObject* _make_buffer_object(float* vertices, unsigned int vsize, unsigned int* indices, unsigned int isize)
{
	DBufferObject* obj;
	if (!MALLOC(obj, sizeof(DBufferObject)))
		return;

	obj->indices = indices;
	obj->indicesSize = isize;

	glGenVertexArrays(1, &obj->vertexArray);
	glGenBuffers(1, &obj->indexBuffer);
	glGenBuffers(1, &obj->vertexBuffer);

	glBindVertexArray(obj->vertexArray);

	glBindBuffer(GL_ARRAY_BUFFER, obj->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vsize, vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, isize, indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	return obj;
}

void _bind_buffer_object(DBufferObject* obj)
{
	glBindVertexArray(obj->vertexArray);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->indexBuffer);
}

void _free_buffer_object(DBufferObject* obj)
{
	FREE(obj);
}
