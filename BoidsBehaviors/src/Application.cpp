#include "Application.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Boid.h"
#include "Shader.h"
#include "Mesh.h"

Application::Application(WindowSpecification windowSpec)
{
	m_Window.Create(windowSpec);
}

Application::~Application()
{
	m_Window.Destroy();

	glfwTerminate();
}

void Application::Run()
{
    const int boidCount = 1;
    Boid boids[boidCount];
    
    for (int i = 0; i < boidCount; ++i)
    {
        boids[i] = Boid((float)i * 10.0f, (float)i * 10.0f, 2.0f, 0.01f);

    }
    Vector2 target(400.0f, 300.0f);

    float vertices[] = {
        -10.0f, -20.0f,
        10.0f, -20.0f,
        0.0f, 10.0f
    };

    glm::vec2 frameBufferSize = m_Window.GetFramebufferSize();
    glm::mat4 proj = glm::ortho(0.0f, (float)frameBufferSize.x, 0.0f, (float)frameBufferSize.y, -1.0f, 1.0f);

    //create shader
    Shader shader("res/shaders/Vertex.shader", "res/shaders/Fragment.shader");
    shader.Bind();
    shader.SetUniformMat4f("u_Projection", proj);
    shader.Unbind();

    Mesh triMesh(vertices, sizeof(vertices), &shader);

    while (!m_Window.ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        //abstract to renderer class?
        for (int i = 0; i < 1; i++)
        {
            Vector2 pos = boids[i].m_position;
            Vector2 vel = boids[i].m_velocity.Normalized();

            float lookDirection = std::atan2(vel.m_y, vel.m_x) - glm::radians(90.0f);

            glm::vec3 position(pos.m_x, pos.m_y, 0.0f);
            glm::vec4 colour(0.2f, 0.3f, 0.8f, 1.0f);

            triMesh.DrawMesh(position, lookDirection, colour);
        }
        for (int i = 0; i < boidCount; i++)
        {
            boids[i].Update(target);
        }

        m_Window.Update();
        glfwPollEvents();
    }
}