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

	//Functions
	glm::mat4* getMatrix(unsigned int i);
	Shader getShader(unsigned int i);

	void Draw();					
};

#endif