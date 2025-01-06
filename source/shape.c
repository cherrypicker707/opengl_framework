#include <opengl_framework/shape.h>
#include <glad/glad.h>
#include <stdlib.h>

#define ATTRIBUTE_LOCATION_POSITION 0
#define ATTRIBUTE_LOCATION_NORMAL 1
#define ATTRIBUTE_LOCATION_COLOR 2
#define ATTRIBUTE_LOCATION_TEXTURE_POSITION 3

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
    glVertexAttribPointer(ATTRIBUTE_LOCATION_POSITION, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)(0 * sizeof(float)));
    glEnableVertexAttribArray(ATTRIBUTE_LOCATION_POSITION);

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
    float vertex[] = {1.0f, 1.0f, 0.0f, 1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f};
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
    glVertexAttribPointer(ATTRIBUTE_LOCATION_POSITION, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(0 * sizeof(float)));
    glEnableVertexAttribArray(ATTRIBUTE_LOCATION_POSITION);
    glVertexAttribPointer(ATTRIBUTE_LOCATION_TEXTURE_POSITION, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(ATTRIBUTE_LOCATION_TEXTURE_POSITION);

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
