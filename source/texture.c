#include <opengl_framework/texture.h>
#include <glad/glad.h>

unsigned int textureCreateCircle(unsigned int width)
{
    unsigned int pixelCount = width * width;
    unsigned char data[pixelCount * 1];

    for (int index = 0; index < pixelCount; index++)
    {
        unsigned int row = index / width;
        unsigned int column = index % width;
        unsigned int rowOffset = row - width / 2;
        unsigned int columnOffset = column - width / 2;
        unsigned int distanceToOriginSquared = rowOffset * rowOffset + columnOffset * columnOffset;
        unsigned int radiusSquared = (width / 2) * (width / 2);

        if (distanceToOriginSquared <= radiusSquared)
        {
            data[index] = 255;
            continue;
        }

        data[index] = 0;
    }

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, width, width, 0, GL_RED, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    return texture;
}

void textureDestroy(unsigned int texture)
{
    glDeleteTextures(1, &texture);
}
