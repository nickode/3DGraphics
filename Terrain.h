#pragma once
#include <Model.h>

enum TileType {GRASS, DIRT, STONE, WATER};

struct TileModel
{
	Model tileModel;
	TileType tileType;

	TileModel(TileType t);
};

struct Tile
{
public:
	TileModel* tm;
	glm::vec3 position;
	glm::mat4* worldModel;

	Tile() {};
	Tile(TileModel* t, glm::vec3 p)
	{
		tm = t;
		position = p;

		worldModel = new glm::mat4(1.0f);
		*worldModel = glm::translate(*worldModel, position);
	}
};

struct TerrainMap
{
private:
	std::vector<TileModel> tileModels;
	Tile tiles[64][64];
	std::vector<Shader> terrainShaders;

public:
	TerrainMap();
	void generate();
	void draw();
	
};