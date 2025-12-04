#include <iostream>
#include "Mesh.h"

Mesh::Mesh(float* data, unsigned int sizeOfData, Shader* shader)
{
	this->InitRenderData(data, sizeOfData);
	this->shader = shader;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &this->VAO);
}

void Mesh::DrawMesh(glm::vec3& position, float angle, glm::vec4& colour)
{
	if (!this->shader)
	{
		std::cout << "Mesh shader is NULL!!" << std::endl;
		return;
	}

	this->shader->Bind();  

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::rotate(model, angle, glm::vec3(0.0f, 0.0f, 1.0f));

	this->shader->SetUniformMat4f("u_Model", model);
	this->shader->SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 1.0f);

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