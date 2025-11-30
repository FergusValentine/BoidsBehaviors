#pragma once

#include <GL/glew.h>

class Mesh
{
public:
	Mesh(float *data, unsigned int sizeOfData);
	~Mesh();
	void DrawMesh();
private:
	unsigned int VAO;
	//shader
	
	void InitRenderData(float* data, unsigned int sizeOfData);
};
