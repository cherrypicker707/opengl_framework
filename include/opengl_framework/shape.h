#ifndef SHAPE_H
#define SHAPE_H

typedef struct Shape Shape;

Shape *shapeCreateSquare();

Shape *shapeCreateTexturedSquare();

void shapeDestroy(Shape *shape);

void shapeDraw(Shape *shape);

#endif
