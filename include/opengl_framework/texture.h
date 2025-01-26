#ifndef TEXTURE_H
#define TEXTURE_H

typedef unsigned int Texture;

Texture textureCreateCircle(unsigned int width);

void textureDestroy(Texture texture);

#endif
