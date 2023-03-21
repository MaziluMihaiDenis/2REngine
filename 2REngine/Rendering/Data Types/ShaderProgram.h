#pragma once

struct ShaderProgram
{
private:
	unsigned int ID, VertexID, FragmentID;
public:
	ShaderProgram(const char* vertexFn, const char* fragmentFn);
	void Bind();
	void Unbind();
};
