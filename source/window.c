#include <opengl_framework/window.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

struct Window
{
    GLFWwindow *window;
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

void windowClear(Window *window, float red, float green, float blue)
{
    glClearColor(red, green, blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void windowUpdate(Window *window)
{
    glfwSwapBuffers(window->window);
    glfwPollEvents();
}
