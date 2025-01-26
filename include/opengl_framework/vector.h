#ifndef VECTOR_H
#define VECTOR_H

#include <opengl_framework/matrix.h>

typedef struct
{
    float x, y, z;
} Vector;

Vector vectorGetScaled(Vector vector, float scalar);

Vector vectorGetNormalized(Vector vector);

Vector vectorGetSum(Vector left, Vector right);

Vector vectorGetDifference(Vector left, Vector right);

Vector vectorGetTransformed(Vector vector, Matrix transformationMatrix);

float vectorGetLength(Vector vector);

float vectorGetDistance(Vector left, Vector right);

float vectorGetDotProduct(Vector left, Vector right);

#endif
