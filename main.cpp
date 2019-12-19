#include <Shader.h>
#include <Setup.h>
#include <Data.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main()
{

	float vertices[] = {
-0.5f, -0.5f, 0.0f,
 0.5f, -0.5f, 0.0f,
 0.0f,  0.5f, 0.0f
	};

	

	GLFWwindow* window = init();
	VertexBuffer vbo;
	VertexArray vao;
	Shader shader("vertex.shader","fragment.shader");
	
	//Vertex buffers and arrays
	vao.bind();
	vbo.bind();
	vbo.bufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	vao.enable(0,3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);

	//model matrix
	glm::mat4 model = glm::mat4(1.0f);

	//view matrix
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	//projection matrix
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);

		model = glm::mat4(1.0f);		
		//model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 0.2f, 0.7f));
		
		glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		shader.use();
		vao.bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		vao.unbind();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	vbo.deleteThis();
	vao.deleteThis();
	
	glfwTerminate();

	return 0;
}



