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
	//glUniform3fv(glGetUniformLocation(ss.getProgram(), "color"), 1, glm::value_ptr(color));



	Model floor("scene.fbx");

	*floor.model = glm::translate(*floor.model, glm::vec3(0.0f, -10.0f, 0.0f));
	s.models.push_back(floor);

	*c->pos = glm::vec3(0.0f, 0.0f, 0.0f);


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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUniformMatrix4fv(iView, 1, GL_FALSE, glm::value_ptr(*c->view));
		

		

		s.Draw(c);
		glfwSwapBuffers(window);
		glfwPollEvents();
		glfwSetCursorPos(window, 400, 300);
	}


	
	glfwTerminate();

	return 0;
}








