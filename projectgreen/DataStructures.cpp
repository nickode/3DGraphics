#include <DataStructures.h>

Scene::Scene()
{	
	
}

Scene::~Scene()
{
	delete& this->windows;
	delete& this-> events;
	delete& this->textures;
	delete& this->sprites;
}

vector<RenderWindow> Scene::getWindows()
{
	return this->windows;
}

vector<Event> Scene::getEvents()
{
	return this->events;
}

vector<Texture> Scene::getTextures()
{
	return this->textures;
}

vector<Sprite> Scene::getSprites()
{
	return this->sprites;
}