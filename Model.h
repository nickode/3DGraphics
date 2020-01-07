#pragma once
#include <Mesh.h>
#include <Shader.h>


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