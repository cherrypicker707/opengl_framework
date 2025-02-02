#ifndef SHAPE_H
#define SHAPE_H

typedef unsigned int GLObject;

typedef struct
{
    unsigned int vertexCount, indexCount;
    GLObject vertexArray, arrayBuffer, elementArrayBuffer;
} Shape;

Shape *shapeCreateSquare();

Shape *shapeCreateTexturedSquare();

void shapeDestroy(Shape *shape);

void shapeDraw(Shape *shape);

#endif
