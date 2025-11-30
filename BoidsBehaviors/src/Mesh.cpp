#include "Mesh.h"

Mesh::Mesh(float* data, unsigned int sizeOfData)
{
	this->InitRenderData(data, sizeOfData);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &this->VAO);
}

void Mesh::DrawMesh()
{
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

void Mesh::InitRenderData(float* data, unsigned int sizeOfData)
{
	unsigned int VBO;

	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeOfData, data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}