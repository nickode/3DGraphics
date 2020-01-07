#version 440 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
	FragColor = vec4(0.3f,0.4f,0.2f,0.0f);
}