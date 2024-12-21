#include <opengl_framework/shape.h>
#include <glad/glad.h>
#include <stdlib.h>

struct Shape
{
    unsigned int vertexArray, arrayBuffer, elementArrayBuffer;
    unsigned int vertexCount, indexCount;
};

Shape *shapeCreateSquare()
{
    Shape *shape = malloc(sizeof(Shape));

    glGenVertexArrays(1, &shape->vertexArray);
    glBindVertexArray(shape->vertexArray);

    glGenBuffers(1, &shape->arrayBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, shape->arrayBuffer);
    float vertex[] = {1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 0.0f, -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f};
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &shape->elementArrayBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, shape->elementArrayBuffer);
    unsigned int index[] = {0, 1, 2, 0, 2, 3};
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);

    return shape;
}

Shape *shapeCreateTexturedSquare()
{
    Shape *shape = malloc(sizeof(Shape));

    glGenVertexArrays(1, &shape->vertexArray);
    glBindVertexArray(shape->vertexArray);

    glGenBuffers(1, &shape->arrayBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, shape->arrayBuffer);
    float vertex[] = {1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 0.0f, -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f};
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &shape->elementArrayBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, shape->elementArrayBuffer);
    unsigned int index[] = {0, 1, 2, 0, 2, 3};
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);

    return shape;
}

void shapeDestroy(Shape *shape)
{
    glDeleteVertexArrays(1, &shape->vertexArray);
    glDeleteBuffers(1, &shape->arrayBuffer);
    glDeleteBuffers(1, &shape->elementArrayBuffer);

    shape->vertexArray = 0;
    shape->arrayBuffer = 0;
    shape->elementArrayBuffer = 0;
    shape->vertexCount = 0;
    shape->indexCount = 0;

    free(shape);
}

void shapeDraw(Shape *shape)
{
    glBindVertexArray(shape->vertexArray);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
