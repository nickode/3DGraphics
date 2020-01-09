#version 440 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

//out vec4 vertexColor;
//out vec2 TexCoord;
//out vec3 Normal;
uniform vec3 color;
//out vec3 vertexColor;

void main()
{
	//vertexColor = color;
	//vertexColor = vec4(color);
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	//TexCoord = vec2(aTexCoord.x, aTexCoord.y);
	//Normal = vec3(aNormal.x, aNormal.y, aNormal.z);
}