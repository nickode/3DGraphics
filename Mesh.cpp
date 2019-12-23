#include <Mesh.h>

void Mesh::loadFromObjFile(const char* filename)
{
	std::ifstream objfile(filename);
	std::string line;
	std::getline(objfile, line);

	while (line != "") {
		std::getline(objfile, line);
		std::cout << line << std::endl;
	}
}