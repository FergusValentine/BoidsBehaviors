#include "Application.h"

int main(void)
{
    WindowSpecification windowSpec;
    windowSpec.title = "Boids Test Application";
    windowSpec.width = 800;
    windowSpec.height = 600;

    Application app(windowSpec);
    app.Run();

    return 0;
}