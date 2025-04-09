#version 330 core

out vec4 FragColor; // Az adott fragment (pixel) színe

in vec3 FragPos; // A fragment pozíciója a világkoordinátákban

void main()
{
    // Egyszerű zöld szín, amit a terrain megjelenítésére használunk
    FragColor = vec4(0.0, 1.0, 0.0, 1.0);
}
