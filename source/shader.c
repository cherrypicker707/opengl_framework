#include <opengl_framework/shader.h>
#include <opengl_framework/file.h>
#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>

Shader shaderCreate(const char *path, ShaderType shaderType)
{
    char *source = fileGetContent(path);

    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, (const char *const *)&source, NULL);
    glCompileShader(shader);

    free(source);
    source = NULL;

    shaderShowCompilingErrors(shader);

    return shader;
}

void shaderShowCompilingErrors(Shader shader)
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

void shaderDestroy(Shader shader)
{
    glDeleteShader(shader);
}
