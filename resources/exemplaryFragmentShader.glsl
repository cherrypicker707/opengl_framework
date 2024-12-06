#version 460 core

out vec4 fragmentColor;

void main()
{
    vec4 fragmentCoordinates = gl_FragCoord;
    vec4 origin = vec4(640, 360, 0.0, 1.0);
    // fragmentColor = vec4(1.0, 0.0, 0.0, 1.0);
    if(distance(fragmentCoordinates, origin) < 100.0)
        fragmentColor = vec4(1.0, 1.0, 1.0, 1.0);
}
