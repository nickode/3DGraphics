#ifndef CAMERA
#define CAMERA

#include <openglstarterpack.h>

class Camera 
{
	
public:
	//Relevant vectors
	glm::vec3* pos;
	glm::vec3* front;
	glm::vec3* up;
	glm::vec3* right;
	glm::mat4* view;
	glm::vec3* ray_wor;
	glm::vec3 nullY = glm::vec3(1.0f, 0.0f, 1.0f);

	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
	float speed = 0.5f; // 3 units / second
	float mouseSpeed = 0.05f;
	float fps;

	bool isCrouched = false;
	

	Camera();
	~Camera();

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void crouch();

	

};

#endif




