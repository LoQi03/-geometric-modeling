#version 330 core

layout (location = 0) in vec3 position; // A vertex pozíciója (x, y, z)

out vec3 FragPos; // A fragment pozíciója, amit majd a fragment shader használ

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // A vertex pozíciója a világkoordinátákban
    FragPos = vec3(model * vec4(position, 1.0));
    
    // A végső pozíció, amit a képernyőre vetítünk
    gl_Position = projection * view * vec4(FragPos, 1.0);
}
