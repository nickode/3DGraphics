#include <Camera.h>

Camera::Camera()
{
	up = new glm::vec3(0.0f, 1.0f, 0.0f);
	pos = new glm::vec3(0.0f, 0.0f, 0.0f);
	front = new glm::vec3(0.0f, 0.0f, -1.0f);
	right = new glm::vec3(glm::normalize(glm::cross(*up, *front)));
	view = new glm::mat4(lookAt(*pos, *pos + *front, *up));
	projection = new glm::mat4(glm::perspective(glm::radians(fov), 4.0f / 3.0f, 0.1f, 100.0f));
	
	ray_wor = new glm::vec3(1.0f);

	*front = glm::vec3(cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle));

	*right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f));

	*up = glm::cross(*right, *front);
}
 
Camera::~Camera()
{
	delete up;
	delete pos;
	delete front;
	delete right;
	delete view;
}

void Camera::moveUp()
{
	*pos += speed * *front;
}

void Camera::moveDown()
{
	*pos -= speed * *front;
}

void Camera::moveRight()
{
	*pos += speed * *right ;
}

void Camera::moveLeft()
{
	*pos -= speed * *right ;
}

void Camera::crouch()
{
	isCrouched = true;
	pos->y -= 3.0f;
}