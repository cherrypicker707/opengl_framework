#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdbool.h>

typedef struct Window Window;

Window *windowCreate(int width, int height, const char *title);

void windowDestroy(Window *window);

bool windowIsOpen(Window *window);

void windowSetBackgroundColor(Window *window, float red, float green, float blue);

void windowClear(Window *window);

void windowClearInColor(Window *window, float red, float green, float blue);

void windowUpdate(Window *window);

#endif
