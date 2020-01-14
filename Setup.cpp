#include <Setup.h>

GLFWwindow* window;
Camera* c;

glm::mat4 projection;
float fov = 45.0f;

double currentTime = 0.0;
double lastTime = 0.0;
float deltaTime = 0.0;
int8_t fpsFlag = 0;
int8_t inputFlag = 0;
int8_t stopFps = 0;
int8_t stopInput = 0;

void mouse_callback_fpv(GLFWwindow* window, double xpos, double ypos)
{


	c->horizontalAngle += c->mouseSpeed * deltaTime * float(800 / 2 - xpos);
	c->verticalAngle += c->mouseSpeed * deltaTime * float(600 / 2 - ypos);

	*c->front = glm::vec3(cos(c->verticalAngle) * sin(c->horizontalAngle),
		sin(c->verticalAngle),
		cos(c->verticalAngle) * cos(c->horizontalAngle));

	*c->right = glm::vec3(sin(c->horizontalAngle - 3.14f / 2.0f),
		0,
		cos(c->horizontalAngle - 3.14f / 2.0f));

	*c->up = glm::cross(*c->right, *c->front);

	//std::cout << "front: " << c->pos->x << "," << c->pos->y << "," << c->pos->z << std::endl;

	//Calculate camera ray vector
	float x = (2.0f * xpos) / 800 - 1.0f;
	float y = 1.0f - (2.0f * ypos) / 600;
	float z = 1.0f;

	glm::vec4 ray_eye = glm::inverse(projection) * glm::vec4(x, y, -1.0, 1.0);
	ray_eye.z = -1.0;
	ray_eye.w = 1.0;
	*c->ray_wor = glm::normalize(glm::vec3((glm::inverse(*c->view) * ray_eye).x, (glm::inverse(*c->view) * ray_eye).y, (glm::inverse(*c->view) * ray_eye).z));

	

}

void fps_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		glfwSetKeyCallback(window, &fps_key_callback);
}

void processInput()
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		c->moveUp();
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		c->moveDown();
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		c->moveLeft();
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		c->moveRight();
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		if (!c->isCrouched)
			c->crouch();
	}
	else if(c->isCrouched)
	{
		c->isCrouched = false;
		c->pos->y += 3.0f;
	}
			
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
	//if (key == GLFW_KEY_E && action == GLFW_PRESS) 
		
}

void godmode_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
		c->moveUp();
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
		c->moveDown();
	if (key == GLFW_KEY_A && action == GLFW_PRESS)
		c->moveLeft();
	if (key == GLFW_KEY_D && action == GLFW_PRESS)
		c->moveRight();
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		glfwSetKeyCallback(window, &fps_key_callback);
		
};


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	projection = glm::perspective(glm::radians(fov), 4.0f / 3.0f, 0.1f, 100.0f);
};

GLFWwindow* init(unsigned int width, unsigned int height)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(width, height, "Greenbag", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return nullptr;
	}

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return nullptr;
	}

	glViewport(0, 0, 800, 600);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glEnable(GL_DEPTH_TEST);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	c = new Camera();

	
	
	return window;
};