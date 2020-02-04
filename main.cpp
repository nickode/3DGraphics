/*
#include <RenderSystem.h>

int main()
{

	StartupRenderEngine();
	
	while (!glfwWindowShouldClose(window))
	{

		currentTime = glfwGetTime();
		deltaTime = float(currentTime - lastTime);
		lastTime = currentTime;

		//c->pos->y += 10.0f;
		//c->pos->z += 30.0f;
		*c->view = glm::lookAt(*c->pos, *c->pos + *c->front, *c->up);

		processInput();
		//*c->pos = s->models[0].position;

		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUniformMatrix4fv(iView, 1, GL_FALSE, glm::value_ptr(*c->view));

		s->Draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
		glfwSetCursorPos(window, width / 2, height / 2);
	}

	glfwTerminate();

	return 0;
}
*/








