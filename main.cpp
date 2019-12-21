#include <Setup.h>
#include <Camera.h>
#include <thread>

//Game Objects
GLFWwindow* window;
Camera cam;

VertexArray* vao;
VertexBuffer* vbo;

//Useful variables
double currentTime = 0.0;
double lastTime = 0.0;
float deltaTime = 0.0;

bool drawFlag = 0;

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		*cam.pos += 0.05f * *cam.front;else
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		*cam.pos -= 0.05f * *cam.front;else
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		*cam.pos -= 0.05f * *cam.right;else
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		*cam.pos += 0.05f * *cam.right;
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
};

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
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

int main()
{

	//model matrix
	glm::mat4 model = glm::mat4(1.0f);

	//glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	float vertices[] = {          
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};
	

	window = initOpenGL();
	glfwSetCursorPosCallback(window, mouse_callback);
	//ElementBuffer ebo;
	vao = new VertexArray();
	vbo = new VertexBuffer();
	Shader shader("vertex.shader","fragment.shader");
	
	//Vertex buffers and arrays
	vao->bind();
	vbo->bind();
	vbo->bufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//ebo.bind();
	//ebo.bufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	vao->enable(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	float initialFoV = 45.0f;
	projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	shader.use();
	

	while (!glfwWindowShouldClose(window))
	{		

		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		*cam.view = glm::lookAt(*cam.pos, *cam.pos + *cam.front, *cam.up);
		glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "view"), 1, GL_FALSE, glm::value_ptr(*cam.view));
		glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		vao->bind();
		glDrawArrays(GL_TRIANGLES, 0, 36);
		vao->unbind();

		glfwSwapBuffers(window);
		glfwPollEvents();
		glfwSetCursorPos(window, 400, 300);
	}


	//ebo.deleteThis();
	vbo->deleteThis();
	vao->deleteThis();

	
	
	glfwTerminate();

	return 0;
}








