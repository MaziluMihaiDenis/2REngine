#include "BufferObject.h"
#include "../../2relibrary.h"
#include "../../External/Glad/glad.h"

BufferObject* _make_buffer_object(float* vertices, unsigned int vsize, unsigned int* indices, unsigned int isize)
{
	BufferObject* obj;
	if (!MALLOC(obj, sizeof(BufferObject)))
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

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	return obj;
}

void _bind_buffer_object(BufferObject* obj)
{
	glBindVertexArray(obj->vertexArray);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->indexBuffer);
}

void _free_buffer_object(BufferObject* obj)
{
	FREE(obj);
}