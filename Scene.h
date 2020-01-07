#ifndef AAA_HEADER
#define AAA_HEADER

#include <Model.h>
#include <Setup.h>

extern Shader shader("vertex.shader", "fragment.shader");

class Scene
{
private:
	std::vector<Model> models;
public:
	void addCylinder();

		void translateById(float x, float y, float z, unsigned int i);

		glm::mat4 getModel(unsigned int i);

		void Draw();
};

extern Scene scene;


#endif