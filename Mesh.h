#pragma once
#include <vector>
#include <openglstarterpack.h>
#include <fstream>
#include <sstream>
#include <iostream>
#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>


class Mesh
{
public:
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	std::vector <unsigned int> v_indices;

	unsigned int nb_vertices = 0;
	void loadFromObjFile(const char* filename);
	void tinyLoader(const char* filename);
};
