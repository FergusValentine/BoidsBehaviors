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

static GLFWwindow* applicationWindow;

static const int boidCount = 1;
static Boid boids[boidCount];

static Vector2 target(400.0f, 300.0f);

static void InitializeOpenGL()
{
    if (!glfwInit())
        std::exit(1);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    applicationWindow = glfwCreateWindow(800, 600, "Boids Simulation", NULL, NULL);
    if (!applicationWindow)
    {
        glfwTerminate();
        std::exit(1);
    }

	glfwMakeContextCurrent(applicationWindow);
    glewInit();

    int fbWidth, fbHeight;
    glfwGetFramebufferSize(applicationWindow, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);

    glfwSwapInterval(1);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

static void InitializeBoids()
{
    for (int i = 0; i < boidCount; ++i)
    {
        boids[i] = Boid((float)i*10.0f, (float)i * 10.0f, 2.0f, 0.01f);
    }
}

static void UpdateBoids()
{
    for (int i = 0; i < boidCount; i++) 
    {
		boids[i].Update(target);
    }
}

static void MainLoop()
{
    //isosceles triangle
    float vertices[] = {
        -10.0f, -20.0f,
        10.0f, -20.0f,
        0.0f, 10.0f
    };


    int fbWidth, fbHeight;
    glfwGetFramebufferSize(applicationWindow, &fbWidth, &fbHeight);

    glm::mat4 proj = glm::ortho(0.0f, (float)fbWidth, 0.0f, (float)fbHeight, -1.0f, 1.0f);
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

    //create shader
    Shader shader("res/shaders/Vertex.shader", "res/shaders/Fragment.shader");
    shader.Bind();
    shader.SetUniformMat4f("u_Projection", proj);
    shader.Unbind();
        
    Mesh triMesh(vertices, sizeof(vertices), &shader);

    while (!glfwWindowShouldClose(applicationWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        //render
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

        glfwSwapBuffers(applicationWindow);
        glfwPollEvents();
    }
}

int main(void)
{
	InitializeOpenGL();
    InitializeBoids();

    MainLoop();

    glfwTerminate();
    return 0;
}