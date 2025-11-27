#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Vector2.h"
#include "Boid.h"

static GLFWwindow* applicationWindow;

static const int boidCount = 1;
static Boid boids[boidCount];

static const Vector2 target(20.0f, 20.0f);

static void InitializeOpenGL()
{
    if (!glfwInit())
        std::exit(1);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glewInit();

    applicationWindow = glfwCreateWindow(800, 600, "Boids Simulation", NULL, NULL);
    if (!applicationWindow)
    {
        glfwTerminate();
        std::exit(1);
    }

	glfwMakeContextCurrent(applicationWindow);
    glfwSwapInterval(1);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

static void VertexInitialize()
{
    unsigned int vao;
    glGenVertexArrays(1, &vao);

    float vertices[] = {
        -0.5f, -0.5,
        0.5f, -0.5f,
        0.0f, 0.5f
    };

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

static void InitializeBoids()
{
    for (int i = 0; i < boidCount; ++i)
    {
        boids[i] = Boid(0.0f, 0.0f, 2.0f, 0.05f);
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
    while (!glfwWindowShouldClose(applicationWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);

		UpdateBoids();

        glfwSwapBuffers(applicationWindow);
        glfwPollEvents();
    }
}

int main(void)
{
	InitializeOpenGL();
    VertexInitialize();
    InitializeBoids();

    MainLoop();

    glfwTerminate();
    return 0;
}