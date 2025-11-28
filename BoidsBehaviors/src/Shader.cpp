#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Shader.h"


Shader::Shader()
{

}

ShaderProgramSource Shader::ParseShader(const std::string& vertexPath, const std::string &fragmentPath)
{
	std::ifstream vertexStream(vertexPath);
	std::ifstream fragmentStream(fragmentPath);

	std::stringstream vertexShaderBuffer;
	std::stringstream fragmentShaderBuffer;

	vertexShaderBuffer << vertexStream.rdbuf();
	fragmentShaderBuffer << fragmentStream.rdbuf();

	vertexStream.close();
	fragmentStream.close();

	return { vertexShaderBuffer.str(), fragmentShaderBuffer.str() };
}

int Shader::CreateShader(const char* source, unsigned int type)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
}