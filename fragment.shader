#version 440 core
out vec4 FragColor;

<<<<<<< HEAD
in vec2 TexCoords;
=======
//in vec3 vertexColor;

//in vec2 TexCoord;
//in vec4 vertexColor;
//uniform sampler2D ourTexture;
>>>>>>> d7375a0885c7225b052c80d5c50b7391eb40a708

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;

void main()
{
<<<<<<< HEAD
	FragColor = texture(texture_diffuse1, TexCoords);
=======
	FragColor = vec4(30.0f,30.0f,30.0f, 0.0f);
>>>>>>> d7375a0885c7225b052c80d5c50b7391eb40a708
}