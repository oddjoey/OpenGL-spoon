#version 330 core

// Output color (RGBA)
out vec4 FragColor;

// Input color from Vertex Shader
in vec3 color;

void main()
{
   FragColor = vec4(color, 1.0f);
}