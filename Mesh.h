#pragma once
#include <vector>
#include <openglstarterpack.h>
#include <fstream>
#include <sstream>
#include <iostream>



class Mesh
{
public:


	std::vector <unsigned int> v_indices;

	unsigned int nb_vertices = 0;
	void loadFromObjFile(const char* filename);
	void tinyLoader(const char* filename);
};
