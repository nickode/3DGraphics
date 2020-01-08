#include <Shader.h>

unsigned int Shader::getProgram()
{
	return program;
}

Shader::Shader(const char* vfile, const char* ffile)
{
	program = glCreateProgram();

	std::ifstream t(vfile);
	std::string vshader((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	//convert to char*
	const char* vshaderc = vshader.c_str();

	vertexshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexshader, 1, &vshaderc, NULL);
	glCompileShader(vertexshader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexshader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	std::ifstream f(ffile);
	std::string fshader((std::istreambuf_iterator<char>(f)),
		std::istreambuf_iterator<char>());

	//convert to char*
	const char* fshaderc = fshader.c_str();

	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader, 1, &fshaderc, NULL);
	glCompileShader(fragmentshader);

	glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentshader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	glAttachShader(program, vertexshader);
	glAttachShader(program, fragmentshader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR LINKING" << std::endl;
	}
}

void Shader::use()
{
	glUseProgram(program);
}


