#version 460 core

layout (location = 0) in vec2 attributePosition;

void main()
{
    gl_Position = vec4(attributePosition, 1.0, 1.0);
}
