#include <opengl_framework/program.h>
#include <opengl_framework/shader.h>
#include <glad/glad.h>
#include <stddef.h>
#include <stdio.h>

Program programCreate(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    Shader vertexShader = shaderCreate(vertexShaderPath, GL_VERTEX_SHADER);
    Shader fragmentShader = shaderCreate(fragmentShaderPath, GL_FRAGMENT_SHADER);

    Program program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    shaderDestroy(vertexShader);
    shaderDestroy(fragmentShader);

    programShowLinkingErrors(program);

    return program;
}

void programDestroy(Program program)
{
    glDeleteProgram(program);
}

void programShowLinkingErrors(Program program)
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

void programUse(Program program)
{
    glUseProgram(program);
}
