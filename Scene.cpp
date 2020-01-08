#include <Scene.h>

glm::mat4 Scene::getModel(unsigned int i)
{
	return models[i].model;
	
}

void Scene::Draw()
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		glUniformMatrix4fv(glGetUniformLocation(models[i].getShaderProgram(), "model"), 1, GL_FALSE, glm::value_ptr(getModel(i)));
		models[i].Draw();
	}
}

Camera Scene::getCamera(unsigned int i)
{
	return cameras[i];
}