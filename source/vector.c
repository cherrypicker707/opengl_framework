#include <opengl_framework/vector.h>
#include <math.h>

Vector vectorGetScaled(Vector vector, float scalar)
{
    vector.x *= scalar;
    vector.y *= scalar;
    vector.z *= scalar;

    return vector;
}

Vector vectorGetNormalised(Vector vector)
{
    float length = vectorGetLength(vector);

    if (length != 0.0f)
        vector = vectorGetScaled(vector, 1.0f / length);

    return vector;
}

Vector vectorGetDifference(Vector left, Vector right)
{
    Vector difference;
    difference.x = left.x - right.x;
    difference.y = left.y - right.y;
    difference.z = left.z - right.z;

    return difference;
}

Vector vectorGetTransformed(Vector vector, Matrix transformationMatrix)
{
    Vector result;

    result.x = transformationMatrix[0] * vector.x + transformationMatrix[1] * vector.y + transformationMatrix[2] * vector.x + transformationMatrix[3];
    result.y = transformationMatrix[4] * vector.x + transformationMatrix[5] * vector.y + transformationMatrix[6] * vector.x + transformationMatrix[7];
    result.z = transformationMatrix[8] * vector.x + transformationMatrix[9] * vector.y + transformationMatrix[10] * vector.x + transformationMatrix[11];
    float w = transformationMatrix[12] * vector.x + transformationMatrix[13] * vector.y + transformationMatrix[14] * vector.x + transformationMatrix[15];

    result.x /= w;
    result.y /= w;
    result.z /= w;

    return result;
}

float vectorGetLength(Vector vector)
{
    float lengthSquared = vectorGetDotProduct(vector, vector);

    return sqrt(lengthSquared);
}

float vectorGetDistance(Vector left, Vector right)
{
    Vector difference = vectorGetDifference(left, right);

    return vectorGetLength(difference);
}

float vectorGetDotProduct(Vector left, Vector right)
{
    return left.x * right.x + left.y * right.y;
}
