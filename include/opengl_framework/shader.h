#ifndef SHADER_H
#define SHADER_H

unsigned int shaderCreate(const char *path, unsigned int type);

void shaderShowCompilingErrors(unsigned int shader);

void shaderDestroy(unsigned int shader);

#endif
