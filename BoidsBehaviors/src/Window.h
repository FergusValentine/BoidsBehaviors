#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

struct WindowSpecification
{
	std::string title;
	unsigned int width;
	unsigned int height;
};

class Window
{
public:
	Window();
	~Window();
	void Create(WindowSpecification windowSpec);
	void Update();
	void Destroy();

	bool ShouldClose() const;

	glm::vec2 GetFramebufferSize() const;
	GLFWwindow* m_Window;
private:
	
};
