#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#include "Vector2.h"
#include "Boid.h"
#include "Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Mesh.h"
#include "Window.h"

//boid manager 
static const int boidCount = 1;
static Boid boids[boidCount];
//

static Vector2 target(400.0f, 300.0f);//replace with local

//TO DO: boid manager
static void InitializeBoids()//
{
    for (int i = 0; i < boidCount; ++i)
    {
        boids[i] = Boid((float)i*10.0f, (float)i * 10.0f, 2.0f, 0.01f);
    }
}

static void UpdateBoids()//
{
    for (int i = 0; i < boidCount; i++) 
    {
		boids[i].Update(target);
    }
}

static void Application(WindowSpecification windowSpec)
{
    Window appWindow;
    appWindow.Create(windowSpec);

    //isosceles triangle
    float vertices[] = {
        -10.0f, -20.0f,
        10.0f, -20.0f,
        0.0f, 10.0f
    };

    glm::vec2 frameBufferSize = appWindow.GetFramebufferSize();
    glm::mat4 proj = glm::ortho(0.0f, (float)frameBufferSize.x, 0.0f, (float)frameBufferSize.y, -1.0f, 1.0f);

    //create shader
    Shader shader("res/shaders/Vertex.shader", "res/shaders/Fragment.shader");
    shader.Bind();
    shader.SetUniformMat4f("u_Projection", proj);
    shader.Unbind();

    Mesh triMesh(vertices, sizeof(vertices), &shader);

    while (!appWindow.ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        //abstract to renderer class?
        for (int i = 0; i < boidCount; i++)
        {
            Vector2 pos = boids[i].m_position;
            Vector2 vel = boids[i].m_velocity.Normalized();

            float lookDirection = std::atan2(vel.m_y, vel.m_x) - glm::radians(90.0f);

            glm::vec3 position(pos.m_x, pos.m_y, 0.0f);
            glm::vec4 colour(0.2f, 0.3f, 0.8f, 1.0f);

            triMesh.DrawMesh(position, lookDirection, colour);
        }
        UpdateBoids();

        appWindow.Update();        
        glfwPollEvents();
    }
}

int main(void)
{
    InitializeBoids();//use manager

    WindowSpecification windowSpec;
    windowSpec.title = "Boids Test Application";
    windowSpec.width = 800;
    windowSpec.height = 600;

    Application(windowSpec);

    glfwTerminate();
    return 0;
}