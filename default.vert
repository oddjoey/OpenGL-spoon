#version 330 core

// [Position]
layout (location = 0) in vec3 aPos;
// [Color]
layout (location = 1) in vec3 aColor;

// Outputs to next shader (fragment)
out vec3 vertexColor;

// Matrices for 3D
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
   gl_Position = projection * view * model * vec4(aPos, 1.0f);
   vertexColor = aColor;
}