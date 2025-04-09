#version 330 core
layout(location = 0) in vec3 aPosition;
uniform mat4 lightSpaceMatrix;  // A fényforrás nézete
void main()
{
    gl_Position = lightSpaceMatrix * vec4(aPosition, 1.0);
}