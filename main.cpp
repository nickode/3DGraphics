#include <Setup.h>
#include <Camera.h>
#include <Shader.h>
#include <World.h>

//Game Objects
GLFWwindow* window;

VertexArray* vao;
VertexBuffer* vbo;

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		*cam.pos += cam.speed * deltaTime * *cam.front;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		*cam.pos -= cam.speed * deltaTime * *cam.front;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		*cam.pos -= cam.speed * deltaTime * *cam.right;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		*cam.pos += cam.speed * deltaTime * *cam.right;
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
};

int main()
{
	World world;

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
	

	window = initOpenGL(800,600);
	glfwSetCursorPosCallback(window, mouse_callback_fpv);
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
	shader.use();

	glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(*world.model));
	glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(cam.projection));

	GLint iView = glGetUniformLocation(shader.getProgram(), "view");
	

	while (!glfwWindowShouldClose(window))
	{		

		currentTime = glfwGetTime();
		deltaTime = float(currentTime - lastTime);
		lastTime = currentTime;
		system("CLS");
		std::cout << deltaTime * 1000 << std::flush;


		*cam.view = glm::lookAt(*cam.pos, *cam.pos + *cam.front, *cam.up);
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(*world.model));
		glUniformMatrix4fv(iView, 1, GL_FALSE, glm::value_ptr(*cam.view));
		//glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(cam.projection));

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








