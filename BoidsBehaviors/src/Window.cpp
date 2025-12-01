#include "Window.h"
#include "assert.h"

Window::Window()
{
    glfwInit();
}

Window::~Window()
{
    Destroy();
}

void Window::Create(WindowSpecification windowSpec)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(windowSpec.width, windowSpec.height, windowSpec.title.c_str(), NULL, NULL);
    if (!m_Window)
    {
        glfwTerminate();
        assert(false);
    }

    glfwMakeContextCurrent(m_Window);
    glewInit();

    glm::vec2 frameBufferSize = GetFramebufferSize();
    glViewport(0, 0, frameBufferSize.x, frameBufferSize.y);

    glfwSwapInterval(1);
}

void Window::Destroy()
{
    if (m_Window)
        glfwDestroyWindow(m_Window);

    m_Window = nullptr;
}

void Window::Update()
{
    glfwSwapBuffers(m_Window);
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(m_Window);
}

glm::vec2 Window::GetFramebufferSize()
{
    int w, h;
    glfwGetFramebufferSize(m_Window, &w, &h);
    return { w, h };
}