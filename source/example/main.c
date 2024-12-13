#include "../program.h"
#include "../window.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <assert.h>

#define VERTEX_SHADER_PATH "../resources/exemplary_vertex_shader.glsl"
#define FRAGMENT_SHADER_PATH "../resources/exemplary_fragment_shader.glsl"

int main()
{
    Window *window = windowCreate(1280, 720, "Test Program");
    unsigned int program = programCreate(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

    float vertex[] = {0.0f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f};
    unsigned int vao, vbo;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    while (windowIsOpen(window))
    {
        windowClear(window, 0.0f, 0.0f, 0.0f);

        glUseProgram(program);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        windowUpdate(window);
    }

    programDestroy(program);
    windowDestroy(window);

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    return 0;
}
