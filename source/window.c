#include <opengl_framework/window.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

struct Window
{
    GLFWwindow *window;
    float backgroundColorRed, backgroundColorGreen, backgroundColorBlue;
};

Window *windowCreate(int width, int height, const char *title)
{
    Window *window = malloc(sizeof(Window));

    assert(glfwInit());
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window->window = glfwCreateWindow(width, height, title, NULL, NULL);
    assert(window->window);

    glfwMakeContextCurrent(window->window);
    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
    glViewport(0, 0, width, height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    window->backgroundColorRed = 0.0f;
    window->backgroundColorGreen = 0.0f;
    window->backgroundColorBlue = 0.0f;

    return window;
}

void windowDestroy(Window *window)
{
    glfwDestroyWindow(window->window);

    glfwTerminate();

    free(window);
}

bool windowIsOpen(Window *window)
{
    return !glfwWindowShouldClose(window->window);
}

void windowSetBackgroundColor(Window *window, float red, float green, float blue)
{
    window->backgroundColorRed = red;
    window->backgroundColorGreen = green;
    window->backgroundColorBlue = blue;
}

void windowClear(Window *window)
{
    glClearColor(window->backgroundColorRed, window->backgroundColorGreen, window->backgroundColorBlue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void windowClearInColor(Window *window, float red, float green, float blue)
{
    glClearColor(red, green, blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void windowUpdate(Window *window)
{
    glfwSwapBuffers(window->window);
    glfwPollEvents();
}
