#ifndef MATRIX_H
#define MATRIX_H

void matrixClear(float *matrix);

void matrixSetIdentity(float *matrix);

void matrixSetScaling(float *matrix, float x, float y, float z);

void matrixSetTranslation(float *matrix, float x, float y, float z);

void matrixSetRotation(float *matrix, float x, float y, float z);

void matrixSetProduct(float *matrix, float *left, float *right);

void matrixTransform(float *matrix, float *other);

#endif
