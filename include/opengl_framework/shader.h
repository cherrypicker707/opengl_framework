#ifndef SHADER_H
#define SHADER_H

typedef unsigned int Shader;
typedef unsigned int ShaderType;

Shader shaderCreate(const char *path, ShaderType shaderType);

void shaderShowCompilingErrors(Shader shader);

void shaderDestroy(Shader shader);

#endif
