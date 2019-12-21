#include <Camera.h>

Camera::Camera()
{
	lastX = 400, lastY = 300;
	yaw = -90.0f;
	pitch = 0.0f;

	up = new glm::vec3(0.0f, 1.0f, 0.0f);
	pos =	new glm::vec3(0.0f, 0.0f, 3.0f);
	front = new glm::vec3(0.0f, 0.0f, -1.0f);
	right = new glm::vec3(glm::normalize(glm::cross(*up, *front)));
	view = new glm::mat4(lookAt(*pos, *pos + *front, *up));
}
