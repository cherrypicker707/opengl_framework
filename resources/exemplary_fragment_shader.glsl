#version 460 core

in vec2 vertexTexturePosition;

out vec4 fragmentColor;

uniform sampler2D circleTexture;

void main()
{
    fragmentColor = texture(circleTexture, vertexTexturePosition);
}
