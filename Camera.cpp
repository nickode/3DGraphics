#include <Camera.h>

Camera cam;

Camera::Camera()
{
	up = new glm::vec3(0.0f, 1.0f, 0.0f);
	pos = new glm::vec3(0.0f, 0.0f, 3.0f);
	front = new glm::vec3(0.0f, 0.0f, -1.0f);
	right = new glm::vec3(glm::normalize(glm::cross(*up, *front)));
	view = new glm::mat4(lookAt(*pos, *pos + *front, *up));

	*front = glm::vec3(cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle));

	*cam.right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f));

	*up = glm::cross(*right, *front);
	projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
}

Camera::~Camera()
{
	delete up;
	delete pos;
	delete front;
	delete right;
	delete view;
}

void mouse_callback_fpv(GLFWwindow* window, double xpos, double ypos)
{
	cam.horizontalAngle += cam.mouseSpeed * deltaTime * float(800 / 2 - xpos);
	cam.verticalAngle += cam.mouseSpeed * deltaTime * float(600 / 2 - ypos);

	*cam.front = glm::vec3(cos(cam.verticalAngle) * sin(cam.horizontalAngle),
		sin(cam.verticalAngle),
		cos(cam.verticalAngle) * cos(cam.horizontalAngle));

	*cam.right = glm::vec3(sin(cam.horizontalAngle - 3.14f / 2.0f),
		0,
		cos(cam.horizontalAngle - 3.14f / 2.0f));

	*cam.up = glm::cross(*cam.right, *cam.front);
}

void Camera::moveUp()
{
	*pos += speed * deltaTime * *front;
}

void Camera::moveDown()
{
	*pos -= speed * deltaTime * *front;
}

void Camera::moveRight()
{
	*cam.pos += cam.speed * deltaTime * *cam.right;
}

void Camera::moveLeft()
{
	*cam.pos -= cam.speed * deltaTime * *cam.right;
}