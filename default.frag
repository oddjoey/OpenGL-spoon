#version 330 core

// Input from previous shader (vertex)
in vec3 vertexColor;

// Fragment shaders NEED a color/vec4 output to produce a final pixel color
out vec4 colorOutput;

void main()
{
   colorOutput = vec4(vertexColor, 1.0f);
}