#include <Scene.h>

void Scene::Draw()
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		glUniformMatrix4fv(glGetUniformLocation(shaders[0].getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(*models[i].model));
		models[i].Draw(shaders[0]);
	}
}