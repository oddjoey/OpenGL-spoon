#version 330 core

// Output color (RGBA)
out vec4 FragColor;

// Input color from Vertex Shader
in vec3 color;

// Input for texture coords
in vec2 texCoord;

uniform sampler2D tex0;

void main()
{
   FragColor = texture(tex0, texCoord);
}