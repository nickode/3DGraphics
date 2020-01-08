#include <Setup.h>
#include <Camera.h>


GLFWwindow* window;

double currentTime = 0.0;
double lastTime = 0.0;
float deltaTime = 0.0;
int8_t fpsFlag = 0;
int8_t inputFlag = 0;
int8_t stopFps = 0;
int8_t stopInput = 0;

void countFps()
{
	while (!stopFps) {
		while (fpsFlag);
		currentTime = glfwGetTime();
		deltaTime = float(currentTime - lastTime);
		lastTime = currentTime;
		fpsFlag--;
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	*projection = glm::perspective(glm::radians(fov), 4.0f / 3.0f, 0.1f, 100.0f);
};

void processInput()
{

	if (glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS)
		moveUp();
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		moveDown();
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		moveLeft();
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		moveRight();
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
		

	
};


GLFWwindow* initOpenGL(unsigned int width, unsigned int height)
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
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glEnable(GL_DEPTH_TEST);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	

	return window;
};