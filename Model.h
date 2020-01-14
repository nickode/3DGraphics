#ifndef MODEL
#define MODEL

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
#include <Shader.h>

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;
	glm::vec3 Bitangent;
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
	void Draw(Shader s);
	bool IntersectCamRay(glm::vec3 rp, glm::vec3 rv, glm::vec3& outIntersectionPoint);
	
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
	glm::mat4* model = new glm::mat4();
	glm::vec3* color = new glm::vec3();
	void Draw(Shader s, glm::vec3 rp, glm::vec3 rv);

	bool cameraRayHit;
private:
	/*  Model Data  */
	std::vector<Mesh> meshes;
	std::vector<Texture> textures_loaded;
	std::string directory;
	
	/*  Functions   */
	void loadModel(std::string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
		std::string typeName);
	
};

#endif