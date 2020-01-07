#include <Scene.h>

void Scene::addCylinder()
{
	const char* filename = "cylinder.obj";
	Model object(filename);
	models.push_back(object);
}
void Scene::translateById(float x, float y, float z, unsigned int i)
{
	models[i].model = glm::translate(models[i].model, glm::vec3(x,y,z));
}
glm::mat4 Scene::getModel(unsigned int i)
{
	return models[i].model;
	
}
void Scene::Draw()
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		models[i].Draw();
		glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(scene.getModel(i)));
	}
}