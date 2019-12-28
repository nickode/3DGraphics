#include <Mesh.h>
#include <Setup.h>
#include <Camera.h>
#include <Shader.h>
#include <thread>
#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

VertexArray* vao;
VertexBuffer* vbo;

int a = 1;

void showFps()
{
	while (a)
	{
		system("CLS");
		std::cout << std::flush;
		std::cout << deltaTime * 1000;
	}
}

int main()
{

	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	const char* filename = "cylinder.obj";
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string warn;
	std::string err;

	bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filename);

	window = initOpenGL(800,600);
	glfwSetCursorPosCallback(window, mouse_callback_fpv);
	ElementBuffer ebo;
	vao = new VertexArray();
	vbo = new VertexBuffer();
	Shader shader("vertex.shader","fragment.shader");
	
	//Vertex buffers and arrays
	vao->bind();
	vbo->bind(); 
	glBufferData(GL_ARRAY_BUFFER, attrib.vertices.size() * sizeof(float), &attrib.vertices[0], GL_STATIC_DRAW);
	
	vao->enable(0, 3, GL_FLOAT, GL_FALSE, 11*sizeof(float), (void*)0);
	vao->enable(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(sizeof(float)*3));
	vao->enable(2, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(sizeof(float) * 3));
	vao->enable(3, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(sizeof(float)*2));
	vao->unbind();

	shader.use();
	glm::vec3* model = new glm::vec3(1.0f);
	glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(*model));
	glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(cam.projection));

	GLint iView = glGetUniformLocation(shader.getProgram(), "view");
	
	std::thread fps(countFps);
	//std::thread input(processInput);


	

	while (!glfwWindowShouldClose(window))
	{		
		fpsFlag++;
		while (!fpsFlag);
		processInput();
		*cam.view = glm::lookAt(*cam.pos, *cam.pos + *cam.front, *cam.up);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(*world.model));
		glUniformMatrix4fv(iView, 1, GL_FALSE, glm::value_ptr(*cam.view));
		//glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(cam.projection));

		vao->bind();
		glDrawArrays(GL_TRIANGLES, 0, 3 * shapes.size());
		vao->unbind();

		glfwSwapBuffers(window);
		glfwPollEvents();
		glfwSetCursorPos(window, 400, 300);
	}

	stopFps++;
	fps.join();
	//stopInput++;
	//input.join();

	delete model;
	model = nullptr;

	a = 0;
	

	vbo->deleteThis();
	vao->deleteThis();
	//cam.~Camera();


	
	glfwTerminate();

	return 0;
}








