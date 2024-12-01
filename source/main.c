#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <assert.h>

int main()
{
    assert(glfwInit());
    GLFWwindow *window = glfwCreateWindow(1280, 720, "Test Program", NULL, NULL);
    assert(window);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
