#version 460 core
out vec4 FragColor;

//in vec2 TexCoord;
in vec4 vertexColor;
//uniform sampler2D ourTexture;


void main()
{

	FragColor = vertexColor;
}