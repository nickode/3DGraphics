#include <Scene.h>

void Scene::Draw()
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		*models[i].model = glm::rotate(*models[i].model, 0.02f, glm::vec3(0.0f,1.0f,0.0f));
		glUniformMatrix4fv(glGetUniformLocation(shaders[0].getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(*models[i].model));
		models[i].Draw(shaders[0]);
	}
}