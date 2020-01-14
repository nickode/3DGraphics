#ifndef SCENE
#define SCENE

#include <Model.h>
#include <Shader.h>
#include <Camera.h>

class Scene
{
public:
	//Data
	std::vector<Model> models;
	std::vector<Shader> shaders;
	//std::vector<Camera> cameras;

	void Draw(Camera* c);					
};

#endif