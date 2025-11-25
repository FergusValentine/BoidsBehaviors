#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


GLFWwindow* applicationWindow;

static void Initialize()
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
}

int main(void)
{
	Initialize();

    while (!glfwWindowShouldClose(applicationWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(applicationWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}