#include <Terrain.h>

TileModel::TileModel(TileType t)
{
	tileType = t;
	tileModel = Model("tile.obj");
}

TerrainMap::TerrainMap()
{
	terrainShaders.push_back(Shader("vertex.shader", "fragment.shader"));

	TileModel grassTileModel(TileType::GRASS);
	tileModels.push_back(grassTileModel);
}

void TerrainMap::generate()
{

	for (int x = 0; x < 64; x++)
	{
		for (int z = 0; z < 64; z++)
		{
			tiles[x][z] = Tile(&tileModels[0], glm::vec3(x,0,z));
		}
	}
}

void TerrainMap::draw()
{
	for (int x = 0; x < 64; x++)
	{
		for (int z = 0; z < 64; z++)
		{
			tiles[x][z].tm->tileModel.getModel() = glm::translate(tiles[x][z].tm->tileModel.getModel(), tiles[x][z].position);
			glUniformMatrix4fv(glGetUniformLocation(terrainShaders[0].getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(tiles[x][z].tm->tileModel.getModel()));
			tiles[x][z].tm->tileModel.Draw();
		}
	}
}

