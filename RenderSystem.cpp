#include <RenderSystem.h>
#include <Scene.h>
#include <iostream>


//Components
GLFWwindow* window;
Camera* c;
Scene* s;

//System Variables
double currentTime;
double lastTime;
float deltaTime;
unsigned int width = 800;
unsigned int height = 600;

//Shader ids
GLint iView;


void mouse_callback_fpv(GLFWwindow* window, double xpos, double ypos)
{
	c->horizontalAngle += c->mouseSpeed * deltaTime * float(width / 2 - xpos);
	c->verticalAngle += c->mouseSpeed * deltaTime * float(height / 2 - ypos);

	//*s->models[0].model = glm::rotate(*s->models[0].model, 0.1f, glm::vec3(0.0f,1.0f,0.0f));

	*c->front = glm::vec3(cos(c->verticalAngle) * sin(c->horizontalAngle),
		sin(c->verticalAngle),
		cos(c->verticalAngle) * cos(c->horizontalAngle));

	*c->right = glm::vec3(sin(c->horizontalAngle - 3.14f / 2.0f),
		0,
		cos(c->horizontalAngle - 3.14f / 2.0f));

	*c->up = glm::cross(*c->right, *c->front);

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
	else if (c->isCrouched)
	{
		c->isCrouched = false;
		c->pos->y += 3.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		s->models[0].rotate(0.01f, glm::vec3(1.0f, 0.0f, 0.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
	//if (key == GLFW_KEY_E && action == GLFW_PRESS) 

}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	*c->projection = glm::perspective(glm::radians(c->fov), 4.0f / 3.0f, 0.1f, 100.0f);
};

void StartupRenderEngine()
{
	//GLFW init stuff, create screen, bla bla dont care
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

	//General Settings
	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	

	//Set callback functions
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, &mouse_callback_fpv);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//Init components
	c = new Camera();
	s = new Scene();

	CubeModel Cube();

	s->c.pos->y -= 100.0f;


	//Load shaders and activate default
	s->shaders.push_back(Shader("vertex.shader", "fragment.shader"));
	Shader ss = s->shaders[0];
	ss.use();

	//Send camera projection to shader
	glUniformMatrix4fv(glGetUniformLocation(ss.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(*c->projection));

	//Set shader ids
	iView = glGetUniformLocation(ss.getProgram(), "view");

}
