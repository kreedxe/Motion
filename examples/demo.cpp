
#include <Motion/Engine.hpp>

int main()
{
    Engine engine;

    if (engine.initGLFW() == EXIT_FAILURE)
    {
        return -1;
    }
    
    while(!glfwWindowShouldClose(engine.window))
    {
        engine.update();
    }

    engine.destroy();
    return 0;
}