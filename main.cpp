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
	glm::vec3 color = glm::vec3(30.0f, 30.0f, 30.0f);

	glUniformMatrix4fv(glGetUniformLocation(ss.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(ss.getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniform3fv(glGetUniformLocation(ss.getProgram(), "color"), 1, glm::value_ptr(color));

<<<<<<< HEAD

	Model floor("floor.obj");
	*floor.model = model;
	s.models.push_back(floor);


	*c->pos = glm::vec3(0.0f, 0.0f, 0.0f);
=======
	for (float x = 0.0f; x < 20.0f; x++)
	{
		for (float z = 0.0f; z < 20.0f; z++)
		{
			Model tile("tile.obj");
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(x,0.0f,z));
			model = glm::scale(model, glm::vec3(1.0f, float(1+std::rand()/((RAND_MAX + 1u)/50)) ,1.0f));
			*tile.model = model;
			glm::vec4 vertcolor = glm::vec4(double(1 + std::rand() / ((RAND_MAX + 1u) / 255)), double(1 + std::rand() / ((RAND_MAX + 1u) / 255)), double(1 + std::rand() / ((RAND_MAX + 1u) / 255)), 0.0f);
			*tile.color = vertcolor;

			s.models.push_back(tile);
		}
	}
>>>>>>> d7375a0885c7225b052c80d5c50b7391eb40a708

	GLint iView = glGetUniformLocation(ss.getProgram(), "view");
	//GLint iHit = glGetUniformLocation(ss.getProgram(), "hit");

	
	//glfwSetKeyCallback(window, &godmode_key_callback);

	while (!glfwWindowShouldClose(window))
	{	
		

		currentTime = glfwGetTime();
		deltaTime = float(currentTime - lastTime);
		lastTime = currentTime;
		*c->view = glm::lookAt(*c->pos, *c->pos + *c->front, *c->up);

		processInput();

		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		glUniformMatrix4fv(iView, 1, GL_FALSE, glm::value_ptr(*c->view));
		

		

		s.Draw(c);
		glfwSwapBuffers(window);
		glfwPollEvents();
		glfwSetCursorPos(window, 400, 300);
	}


	
	glfwTerminate();

	return 0;
}








