#version 460 core

layout (location = 0) in vec3 attributePosition;
layout (location = 1) in vec2 attributeTexturePosition;

out vec2 vertexTexturePosition;

uniform mat4 transformation;

void main()
{
    gl_Position = transformation * vec4(attributePosition, 1.0);
    vertexTexturePosition = (attributeTexturePosition + 1.0) / 2.0;
}
