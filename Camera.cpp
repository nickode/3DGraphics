#include <Camera.h>

Camera::Camera()
{
	up = new glm::vec3(0.0f, 1.0f, 0.0f);
	pos = new glm::vec3(0.0f, 0.0f, 3.0f);
	front = new glm::vec3(0.0f, 0.0f, -1.0f);
	right = new glm::vec3(glm::normalize(glm::cross(*up, *front)));
	view = new glm::mat4(lookAt(*pos, *pos + *front, *up));
	projection = new glm::mat4(1.0f);
	ray_wor = new glm::vec3(1.0f);

	*front = glm::vec3(cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle));

	*right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f));

	*up = glm::cross(*right, *front);
	*projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
}

Camera::~Camera()
{
	delete up;
	delete pos;
	delete front;
	delete right;
	delete view;
}

void Camera::mouse_callback_fpv(GLFWwindow* window, double xpos, double ypos)
{
	//Calculate camera view matrix
	horizontalAngle += mouseSpeed * deltaTime * float(800 / 2 - xpos);
	verticalAngle += mouseSpeed * deltaTime * float(600 / 2 - ypos);

	*front = glm::vec3(cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle));

	*right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f));

	*up = glm::cross(*right, *front);


	//Calculate camera ray vector
	float x = (2.0f * xpos) / 800 - 1.0f;
	float y = 1.0f - (2.0f * ypos) / 600;
	float z = 1.0f;

	glm::vec4 ray_eye = glm::inverse(*projection) * glm::vec4(x, y, -1.0, 1.0);
	ray_eye.z = -1.0;
	ray_eye.w = 1.0;
	*ray_wor = glm::normalize(glm::vec3((glm::inverse(*view) * ray_eye).x, (glm::inverse(*view) * ray_eye).y, (glm::inverse(*view) * ray_eye).z));
	
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
	*pos += speed * *right;
}

void Camera::moveLeft()
{
	*pos -= speed * *right;
}