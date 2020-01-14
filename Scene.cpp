#include <Scene.h>

void Scene::Draw(Camera* c)
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		
		glUniformMatrix4fv(glGetUniformLocation(shaders[0].getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(*models[i].model));
		//glUniform1ui(glGetUniformLocation(shaders[0].getProgram(), "hit"), models[i].cameraRayHit);
		//std::cout << models[i].cameraRayHit << std::endl;
		//shaders[0].setVec3("color",*models[i].color);
		models[i].Draw(shaders[0],*c->pos, *c->front);
		
	}
}