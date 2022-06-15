#version 330 core

in vec2 passTextureCoords;

out vec4 colorOutput;

uniform sampler2D textureSampler;

void main()
{
   colorOutput = texture(textureSampler, passTextureCoords);
}