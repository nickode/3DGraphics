#pragma once
#include <Mesh.h>

void Mesh::tinyLoader(const char* filename)
{
	std::string warn;
	std::string err;

	bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filename);

}

void Mesh::loadFromObjFile(const char* filename)
{
	std::ifstream objfile(filename);
	std::string prop; //currently selected property of the obj file
	std::string line;
	
	float x;
	float y;
	float z;
	

	while (!objfile.eof()) {
		std::getline(objfile, line);
		//objfile.get();
		
		if (line[0] == 'v')
		{
			objfile >> prop; 
			objfile >> x;
			objfile >> y;
			objfile >> z;
			//vertices.push_back(glm::vec3(x,y,z));
			nb_vertices++;
		}

		if (line[0] == 'vn')
		{
			objfile >> prop;
			objfile >> x;
			objfile >> y;
			objfile >> z;
			//normals.push_back(glm::vec3(x, y, z));
		}

	}

	std::cout << "Finished loading" << std::endl;
}