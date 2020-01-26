#include <Camera.h>
#include <thread>
#include <Scene.h>
#include <Setup.h>

int main()
{
	window = init(800,600);
	Scene s;
	s.shaders.push_back(Shader("vertex.shader", "fragment.shader"));
	Shader ss = s.shaders[0];
	ss.use();
	glUniformMatrix4fv(glGetUniformLocation(ss.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(*c->projection));
	



	Model player("scene.fbx");

	*player.model = glm::translate(*player.model, glm::vec3(0.0f, -10.0f, 0.0f));
	*player.model = glm::scale(*player.model, glm::vec3(1.0f, 1.0f, -1.0f));
	s.models.push_back(player);

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
		

		
		
		s.Draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
		glfwSetCursorPos(window, 400, 300);
	}


	
	glfwTerminate();

	return 0;
}








