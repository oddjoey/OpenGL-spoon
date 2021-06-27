#version 330 core

// Position XYZ
layout (location = 0) in vec3 aPos;
// Colors
layout (location = 1) in vec3 aColor;
// Texture XYZ
layout (location = 2) in vec2 aTex;

// Output color for fragment shader
out vec3 color;
// Output texture co0rds to fragment shader
out vec2 texCoord;

// Scale of vertices
uniform float scale;

void main()
{
   gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0);
   color = aColor;
   texCoord = aTex;
}