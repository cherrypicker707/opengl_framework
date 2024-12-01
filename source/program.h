#ifndef PROGRAM_H
#define PROGRAM_H

unsigned int programCreate(const char *vertexShaderPath, const char *fragmentShaderPath);

void programShowLinkingErrors(unsigned int program);

void programDestroy(unsigned int program);

#endif
