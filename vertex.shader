#version 440 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;

out vec2 TexCoords;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

<<<<<<< HEAD

void main()
{
	TexCoords = vec2(aTexCoords.x, aTexCoords.y);
=======
//out vec4 vertexColor;
//out vec2 TexCoord;
//out vec3 Normal;
uniform vec3 color;
//out vec3 vertexColor;

void main()
{
	//vertexColor = color;
	//vertexColor = vec4(color);
>>>>>>> d7375a0885c7225b052c80d5c50b7391eb40a708
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
}