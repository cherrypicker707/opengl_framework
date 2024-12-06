#include "program.h"
#include "shader.h"

#include <glad/glad.h>

#include <stddef.h>
#include <stdio.h>

unsigned int programCreate(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    unsigned int vertexShader = shaderCreate(vertexShaderPath, GL_VERTEX_SHADER);
    unsigned int fragmentShader = shaderCreate(fragmentShaderPath, GL_FRAGMENT_SHADER);

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    shaderDestroy(vertexShader);
    shaderDestroy(fragmentShader);

    programShowLinkingErrors(program);

    return program;
}

void programShowLinkingErrors(unsigned int program)
{
    int status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);

    if (!status)
    {
        char log[1024];
        glGetProgramInfoLog(program, 1024, NULL, log);
        printf("%s\n", log);
    }
}

void programDestroy(unsigned int program)
{
    glDeleteProgram(program);
}
