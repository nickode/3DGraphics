#pragma once
#include <vector>
#include <openglstarterpack.h>
#include <fstream>
#include <sstream>
#include <iostream>

class Mesh
{
private:
	std::vector<glm::vec3> vertices;
public:
	void loadFromObjFile(const char* filename);
};
