#include <opengl_framework/program.h>
#include <opengl_framework/window.h>
#include <opengl_framework/shape.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <assert.h>

#define VERTEX_SHADER_PATH "../resources/exemplary_vertex_shader.glsl"
#define FRAGMENT_SHADER_PATH "../resources/exemplary_fragment_shader.glsl"

int main()
{
    Window *window = windowCreate(1280, 720, "Test Program");
    unsigned int program = programCreate(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
    Shape *square = shapeCreateSquare();

    while (windowIsOpen(window))
    {
        windowClear(window, 0.0f, 0.0f, 0.0f);

        glUseProgram(program);
        shapeDraw(square);

        windowUpdate(window);
    }

    programDestroy(program);
    windowDestroy(window);
    shapeDestroy(square);

    return 0;
}
