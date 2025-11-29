#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#include "Vector2.h"
#include "Boid.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

static GLFWwindow* applicationWindow;

static const int boidCount = 20;
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

    glfwSwapInterval(1);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

static void InitializeBoids()
{
    for (int i = 0; i < boidCount; ++i)
    {
        boids[i] = Boid((float)i*100.0f, (float)i * 100.0f, 5.0f, 0.05f);
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
        -10.0f, -10.0f,
        10.0f, -10.0f,
        0.0f, 30.0f
    };

    //create vertex array object
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //create triangle buffer
    VertexBuffer vertexBuffer(vertices, sizeof(vertices));
    
    //create triangle buffer layout
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    //create shader
    Shader shader("res/shaders/Vertex.shader", "res/shaders/Fragment.shader");
    shader.Bind();
    shader.SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 1.0f);

    vertexBuffer.Unbind();
    
    glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
    //glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

    while (!glfwWindowShouldClose(applicationWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        //render
        for (int i = 0; i < boidCount; i++)
        {
            Vector2 pos = boids[i].m_position;
            glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(pos.m_x, pos.m_y, 0));

            Vector2 newPos = boids[i].m_velocity;
            newPos = newPos.Normalized();
            float r = std::atan2(newPos.m_y, newPos.m_x);
            model = glm::rotate(model, -r, glm::vec3(0.0f, 0.0f, 1.0f));

            glm::mat4 mvp = proj * model;
           
            shader.SetUniformMat4f("u_MVP", mvp);

            glDrawArrays(GL_TRIANGLES, 0, 3);
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