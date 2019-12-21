#include <openglstarterpack.h>

class Camera 
{
	
public:
	glm::vec3* pos;
	glm::vec3* front;
	glm::vec3* up;
	glm::vec3* right;
	glm::mat4* view;

	double yaw;
	double pitch;
	double lastX;
	double lastY;
	double lastTime;

	float fov = 0;
	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
	float speed = 2.0f; // 3 units / second
	float mouseSpeed = 0.05f;
	float fps;

	Camera();

};



