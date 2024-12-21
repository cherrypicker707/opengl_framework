#version 460 core

layout (location = 0) in vec2 attributePosition;

uniform mat4 transformation;

void main()
{
    gl_Position = transformation * vec4(attributePosition, 1.0, 1.0);
}
