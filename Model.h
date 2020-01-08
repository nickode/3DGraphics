#pragma once
#include <vector>
#include <openglstarterpack.h>
#include <fstream>
#include <sstream>
#include <iostream>
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

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);

class Model
{
public:
	/*  Functions   */
	Model(const char* path)
	{
		loadModel(path);
	}
	glm::mat4 model = glm::mat4(1.0f);
	void Draw();

	void setShaderProgram(unsigned int i);
	unsigned int getShaderProgram();
private:
	/*  Model Data  */
	std::vector<Mesh> meshes;
	std::vector<Texture> textures_loaded;
	std::string directory;
	unsigned int shaderId;
	
	/*  Functions   */
	void loadModel(std::string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
		std::string typeName);

};