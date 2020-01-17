#ifndef SCENE
#define SCENE

#include <Model.h>
#include <Shader.h>
#include <Camera.h>

struct Scene
{
public:
	//Data
	std::vector<Model> models;
	std::vector<Shader> shaders;
	Camera c;
public:
	void Draw();
};

#endif