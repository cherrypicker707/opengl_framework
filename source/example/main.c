#include <opengl_framework/program.h>
#include <opengl_framework/window.h>
#include <opengl_framework/shape.h>
#include <opengl_framework/matrix.h>
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

    glUseProgram(program);

    float scaling[16], rotation[16], translation[16], matrix[16];
    matrixSetScaling(scaling, 0.1f, 0.1f, 0.1f);
    matrixSetRotation(rotation, 0.0f, 0.0f, 1.0f);
    matrixSetTranslation(translation, -0.5f, 0.5f, 0.0f);
    matrixSetIdentity(matrix);
    matrixTransform(matrix, scaling);
    matrixTransform(matrix, rotation);
    matrixTransform(matrix, translation);

    glUniformMatrix4fv(glGetUniformLocation(program, "transformation"), 1, true, matrix);

    while (windowIsOpen(window))
    {
        windowClear(window, 0.0f, 0.0f, 0.0f);

        shapeDraw(square);

        windowUpdate(window);
    }

    programDestroy(program);
    windowDestroy(window);
    shapeDestroy(square);

    return 0;
}
