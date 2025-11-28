#pragma once

#include <string>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
public:
	ShaderProgramSource ParseShader(const std::string& vertexPath, const std::string& fragmentPath);
private:
	static int CreateShader(const char* source, unsigned int type);
};