#include <opengl_framework/matrix.h>
#include <math.h>
#include <string.h>

void matrixClear(Matrix matrix)
{
    for (int index = 0; index < 16; index++)
        matrix[index] = 0.0f;
}

void matrixSetIdentity(Matrix matrix)
{
    matrixClear(matrix);

    for (int index = 0; index < 4; index++)
        matrix[index * 4 + index] = 1.0f;
}

void matrixSetScaling(Matrix matrix, float x, float y, float z)
{
    matrixClear(matrix);

    matrix[0] = x;
    matrix[5] = y;
    matrix[10] = z;
    matrix[15] = 1.0f;
}

void matrixSetTranslation(Matrix matrix, float x, float y, float z)
{
    matrixSetIdentity(matrix);

    matrix[3] = x;
    matrix[7] = y;
    matrix[11] = z;
}

void matrixSetRotation(Matrix matrix, float x, float y, float z)
{
    matrix[0] = cos(y) * cos(z);
    matrix[1] = sin(x) * sin(y) * cos(z) - cos(x) * sin(z);
    matrix[2] = cos(z) * sin(y) * cos(z) + sin(z) * sin(z);
    matrix[3] = 0.0f;

    matrix[4] = cos(y) * sin(z);
    matrix[5] = sin(x) * sin(y) * sin(z) + cos(x) * cos(z);
    matrix[6] = cos(x) * sin(y) * sin(z) - sin(x) * cos(z);
    matrix[7] = 0.0f;

    matrix[8] = -sin(y);
    matrix[9] = sin(x) * cos(y);
    matrix[10] = cos(x) * cos(y);
    matrix[11] = 0.0f;

    matrix[12] = 0.0f;
    matrix[13] = 0.0f;
    matrix[14] = 0.0f;
    matrix[15] = 1.0f;
}

void matrixSetProduct(Matrix matrix, Matrix left, Matrix right)
{
    for (int index = 0; index < 16; index++)
    {
        int row = index / 4;
        int column = index % 4;

        matrix[index] = 0.0f;
        for (int offset = 0; offset < 4; offset++)
            matrix[index] += left[row * 4 + offset] * right[offset * 4 + column];
    }
}

void matrixSetOrthographicProjection(float *matrix, float aspect, float scale, float nearPlane, float farPlane)
{
    matrixClear(matrix);

    matrix[0] = scale / aspect;
    matrix[5] = scale;
    matrix[10] = -2.0f / (nearPlane / farPlane);
    matrix[11] = (nearPlane + farPlane) / (nearPlane - farPlane);
    matrix[15] = 1.0f;
}

void matrixSetPerspectiveProjection(Matrix matrix, float aspect, float fieldOfView, float nearPlane, float farPlane)
{
    matrixClear(matrix);

    matrix[0] = 1.0f / (tan(fieldOfView / 2.0f) * aspect);
    matrix[5] = 1.0f / tan(fieldOfView / 2.0f);
    matrix[10] = (nearPlane + farPlane) / (nearPlane - farPlane);
    matrix[11] = -2.0f * nearPlane * farPlane / (nearPlane - farPlane);
    matrix[14] = -1;
}

void matrixTransform(Matrix matrix, Matrix other)
{
    float copy[16];
    memcpy(copy, matrix, 16 * sizeof(float));
    matrixSetProduct(matrix, other, copy);
}
