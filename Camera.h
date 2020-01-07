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
	glm::mat4* projection;

	glm::vec3* ray_wor;

	float fov = 45.0f;
	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
	float speed = 0.10f; // 3 units / second
	float mouseSpeed = 0.05f;
	float fps;

	Camera();
	~Camera();

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	

};

extern Camera cam;

extern void mouse_callback_fpv(GLFWwindow* window, double xpos, double ypos);



