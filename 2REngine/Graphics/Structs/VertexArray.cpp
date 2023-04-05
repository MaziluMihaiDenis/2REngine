#include "VertexArray.h"
#include <External/Glad/glad.h>
extern "C"
{
#include <Basic/core.h>
}

VertexArray::VertexArray(float* vertices, unsigned int vsize, unsigned int* indices, unsigned int isize)
{
	Indices = indices;
	IndicesSize = isize / sizeof(unsigned int);

	glGenVertexArrays(1, &VA_ID);
	glGenBuffers(1, &IB_ID);
	glGenBuffers(1, &VB_ID);

	glBindVertexArray(VA_ID);

	glBindBuffer(GL_ARRAY_BUFFER, VB_ID);
	glBufferData(GL_ARRAY_BUFFER, vsize, vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, isize, indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

VertexArray::~VertexArray()
{
	Unbind();
	glDeleteBuffers(1, &VB_ID);
	glDeleteBuffers(1, &IB_ID);
	glDeleteVertexArrays(1, &VA_ID);
	FREE(Indices);
}

void VertexArray::Bind()
{
	glBindVertexArray(VA_ID);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}
