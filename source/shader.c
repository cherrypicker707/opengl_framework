#include <opengl_framework/shader.h>
#include <opengl_framework/file.h>
#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int shaderCreate(const char *path, unsigned int type)
{
    char *source = fileGetContent(path);

    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, (const char *const *)&source, NULL);
    glCompileShader(shader);

    free(source);
    source = NULL;

    shaderShowCompilingErrors(shader);

    return shader;
}

void shaderShowCompilingErrors(unsigned int shader)
{
    int status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

    if (!status)
    {
        char log[1024];
        glGetShaderInfoLog(shader, 1024, NULL, log);
        printf("%s\n", log);
    }
}

void shaderDestroy(unsigned int shader)
{
    glDeleteShader(shader);
}
