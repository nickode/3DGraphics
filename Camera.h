#include <openglstarterpack.h>
#include <Setup.h>

class Camera 
{
	
public:
	glm::vec3* pos;
	glm::vec3* front;
	glm::vec3* up;
	glm::vec3* right;
	glm::mat4* view;
	glm::mat4 projection;

	float fov = 45.0f;
	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
	float speed = 2.0f; // 3 units / second
	float mouseSpeed = 0.05f;
	float fps;

	Camera();
	

};

extern Camera cam;

void mouse_callback_fpv(GLFWwindow* window, double xpos, double ypos);



