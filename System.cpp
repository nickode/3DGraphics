#include <System.h>

System* sys;

void init()
{
	sys = new System(800, 600);
}

System::System(unsigned int width, unsigned int height)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(width, height, "monk3y", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		
	}

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		
	}

	glViewport(0, 0, 800, 600);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	//glEnable(GL_STENCIL_TEST);
	//glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	glfwSetCursorPosCallback(window, mouse_callback_fpv);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	c = new Camera();


}



void mouse_callback_fpv(GLFWwindow* window, double xpos, double ypos)
{

	sys->c->horizontalAngle += sys->c->mouseSpeed * sys->deltaTime * float(800 / 2 - xpos);
	sys->c->verticalAngle += sys->c->mouseSpeed * sys->deltaTime * float(600 / 2 - ypos);

	*sys->c->front = glm::vec3(cos(sys->c->verticalAngle) * sin(sys->c->horizontalAngle),
		sin(sys->c->verticalAngle),
		cos(sys->c->verticalAngle) * cos(sys->c->horizontalAngle));

	*sys->c->right = glm::vec3(sin(sys->c->horizontalAngle - 3.14f / 2.0f),
		0,
		cos(sys->c->horizontalAngle - 3.14f / 2.0f));

	*sys->c->up = glm::cross(*sys->c->right, *sys->c->front);


};


void processInput()
{
	if (glfwGetKey(sys->window, GLFW_KEY_W) == GLFW_PRESS)
		sys->c->moveUp();
	if (glfwGetKey(sys->window, GLFW_KEY_S) == GLFW_PRESS)
		sys->c->moveDown();
	if (glfwGetKey(sys->window, GLFW_KEY_A) == GLFW_PRESS)
		sys->c->moveLeft();
	if (glfwGetKey(sys->window, GLFW_KEY_D) == GLFW_PRESS)
		sys->c->moveRight();
	if (glfwGetKey(sys->window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		if (!sys->c->isCrouched)
			sys->c->crouch();
	}
	else if (sys->c->isCrouched)
	{
		sys->c->isCrouched = false;
		sys->c->pos->y += 3.0f;
	}

	if (glfwGetKey(sys->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(sys->window, 1);
	//if (key == GLFW_KEY_E && action == GLFW_PRESS) 

};



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	sys->c->projection = glm::perspective(glm::radians(sys->c->fov), 4.0f / 3.0f, 0.1f, 100.0f);
};
