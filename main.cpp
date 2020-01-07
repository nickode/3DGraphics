#include <Camera.h>
#include <thread>
#include <Scene.h>


int main()
{
	window = initOpenGL(800,600);
	glfwSetCursorPosCallback(window, mouse_callback_fpv);


	//World
	scene.addCylinder();
	//scene.addCylinder();
	//scene.translateById(100.0f, 100.0f, 100.0f, 1);


	glm::vec3 cylinderPositions[] = {
	  glm::vec3(0.0f,  0.0f,  0.0f),
	  glm::vec3(2.0f,  5.0f, -15.0f),
	  glm::vec3(-1.5f, -2.2f, -2.5f),
	  glm::vec3(-3.8f, -2.0f, -12.3f),
	  glm::vec3(2.4f, -0.4f, -3.5f),
	  glm::vec3(-1.7f,  3.0f, -7.5f),
	  glm::vec3(1.3f, -2.0f, -2.5f),
	  glm::vec3(1.5f,  2.0f, -2.5f),
	  glm::vec3(1.5f,  0.2f, -1.5f),
	  glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	shader.use();
	glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(*cam.projection));
	
	//glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "model2"), 1, GL_FALSE, glm::value_ptr(scene.getModel(1)));

	GLint iView = glGetUniformLocation(shader.getProgram(), "view");
	
	
	std::thread fps(countFps);
	//std::thread input(processInput);


	

	while (!glfwWindowShouldClose(window))
	{		
		processInput();
		*cam.view = glm::lookAt(*cam.pos, *cam.pos + *cam.front, *cam.up);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glUniformMatrix4fv(iView, 1, GL_FALSE, glm::value_ptr(*cam.view));

		scene.Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
		glfwSetCursorPos(window, 400, 300);
	}

	stopFps++;
	fps.join();
	//stopInput++;
	//input.join();



	
	glfwTerminate();

	return 0;
}








