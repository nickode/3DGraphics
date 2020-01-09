#include <Camera.h>
#include <thread>
#include <Scene.h>
#include <Setup.h>



int main()
{
	window = init(800,600);
	
	glfwSetCursorPosCallback(window, &mouse_callback_fpv);



	Scene s;


	
	s.shaders.push_back(Shader("vertex.shader","fragment.shader"));

	Shader ss = s.shaders[0];
	ss.use();

	glm::mat4 projection = glm::perspective(glm::radians(fov), 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 model = glm::mat4(1.0f);

	glUniformMatrix4fv(glGetUniformLocation(ss.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(ss.getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model));
	

	for (float x = 0.0f; x < 20.0f; x++)
	{
		for (float z = 0.0f; z < 20.0f; z++)
		{
			Model tile("tile.obj");
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(x,0.0f,z));
			double r = ((double)std::rand() / (RAND_MAX + 10));
			model = glm::scale(model, glm::vec3(1.0f, float(1+std::rand()/((RAND_MAX + 1u)/50)) ,1.0f));
			*tile.model = model;
			*tile.color = glm::vec4(float(1 + std::rand() / ((RAND_MAX + 1u) / 255)), float(1 + std::rand() / ((RAND_MAX + 1u) / 255)), float(1 + std::rand() / ((RAND_MAX + 1u) / 255)), 0.0f);

			s.models.push_back(tile);
		}
	}

	GLint iView = glGetUniformLocation(ss.getProgram(), "view");
	


	while (!glfwWindowShouldClose(window))
	{	
		processInput();
		glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUniformMatrix4fv(iView, 1, GL_FALSE, glm::value_ptr(*c->view)); 

		

		s.Draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
		glfwSetCursorPos(window, 400, 300);
	}


	
	glfwTerminate();

	return 0;
}








