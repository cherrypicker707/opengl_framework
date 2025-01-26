#ifndef SHAPE_H
#define SHAPE_H

typedef unsigned int GLObject;

typedef struct
{
    GLObject vertexArray, arrayBuffer, elementArrayBuffer;
    unsigned int vertexCount, indexCount;
} Shape;

Shape *shapeCreateSquare();

Shape *shapeCreateTexturedSquare();

void shapeDestroy(Shape *shape);

void shapeDraw(Shape *shape);

#endif
