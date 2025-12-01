#pragma once

#include "Window.h"

class Application
{
public:
	Application(WindowSpecification windowSpec);
	~Application();

	void Run();
private:
	Window m_Window;

};

