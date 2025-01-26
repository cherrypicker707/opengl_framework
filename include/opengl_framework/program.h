#ifndef PROGRAM_H
#define PROGRAM_H

typedef unsigned int Program;

Program programCreate(const char *vertexShaderPath, const char *fragmentShaderPath);

void programDestroy(Program program);

void programShowLinkingErrors(Program program);

void programUse(Program program);

#endif
