#pragma once
#include <vector>
#include <openglstarterpack.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <assimp/material.h>
#include <assimp/StringUtils.h>
#include <assimp/texture.h>
#include <assimp/types.h>
#include <assimp/mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int id;
	std::string type;
	aiString path;
};

class Mesh
{
public:
	std::vector <Vertex> vertices;
	std::vector <unsigned int> indices;
	std::vector <Texture> textures;
	Mesh(std::vector<Vertex> v, std::vector<unsigned int> i, std::vector<Texture> t);
	void Draw();
private:
	unsigned int VAO, VBO, EBO;
	void setupMesh();
};
