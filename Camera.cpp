#include <Camera.h>

Camera cam;

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

	*cam.right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f),
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

	float x = (2.0f * xpos) / 800 - 1.0f;
	float y = 1.0f - (2.0f * ypos) / 600;
	float z = 1.0f;
	glm::vec4 ray_eye = glm::inverse(*cam.projection) * glm::vec4(x, y, -1.0, 1.0);
	ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0, 1.0);

	cam.ray_wor->x = (glm::inverse(*cam.view) * ray_eye).x;
	cam.ray_wor->y = (glm::inverse(*cam.view) * ray_eye).y;
	cam.ray_wor->z = (glm::inverse(*cam.view) * ray_eye).z;
	// don't forget to normalise the vector at some point
	*cam.ray_wor = glm::normalize(*cam.ray_wor);

	
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
	*cam.pos += cam.speed * *cam.right;
}

void Camera::moveLeft()
{
	*cam.pos -= cam.speed * *cam.right;
}