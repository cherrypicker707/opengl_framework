#ifndef MATRIX_H
#define MATRIX_H

typedef float Matrix[16];

/*
 * [  0  1  2  3 ]
 * [  4  5  6  7 ]
 * [  8  9 10 11 ]
 * [ 12 13 14 15 ]
 */

void matrixClear(Matrix matrix);

void matrixSetIdentity(Matrix matrix);

void matrixSetScaling(Matrix matrix, float x, float y, float z);

void matrixSetTranslation(Matrix matrix, float x, float y, float z);

void matrixSetRotation(Matrix matrix, float x, float y, float z);

void matrixSetProduct(Matrix matrix, Matrix left, Matrix right);

void matrixSetOrthographicProjection(Matrix matrix, float aspect, float scale, float nearPlane, float farPlane);

void matrixSetPerspectiveProjection(Matrix matrix, float aspect, float fieldOfView, float nearPlane, float farPlane);

void matrixTransform(Matrix matrix, Matrix other);

#endif
