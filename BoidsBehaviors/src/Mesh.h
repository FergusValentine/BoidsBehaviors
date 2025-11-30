#pragma once

#include "Shader.h"
#include <GL/glew.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Mesh
{
public:
	Mesh(float* data, unsigned int sizeOfData, Shader* shader);
	~Mesh();
	void DrawMesh(glm::vec3& position, float angle, glm::vec4& colour);
private:
	unsigned int VAO;
	//shader
	Shader* shader;
	
	void InitRenderData(float* data, unsigned int sizeOfData);
};
