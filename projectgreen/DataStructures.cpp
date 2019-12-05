#include <DataStructures.h>


//SCENE CLASS
Scene::Scene()
{	
	
}

Scene::~Scene()
{
	delete& this->windows;
	delete& this->events;
	delete& this->textures;
	delete& this->sprites;
}

string Scene::getName()
{
	return name;
}

void Scene::setName(string n)
{
	name = n;
}

vector<RenderWindow*> Scene::getWindows()
{
	return this->windows;
}

vector<Event*> Scene::getEvents()
{
	return this->events;
}

vector<Texture*> Scene::getTextures()
{
	return this->textures;
}

vector<Sprite*> Scene::getSprites()
{
	return this->sprites;
}

void Scene::printDetails()
{
	using std::cout; using std::cin; using std::endl;

	cout << "Scene: " << name << endl;
	cout << "# of Windows: " << windows.size() << endl;
	cout << "# of Events: " << events.size() << endl;
	cout << "# of Textures: " << textures.size() << endl;
	cout << "# of Sprites: " << sprites.size() << endl;
}

//END SCENE CLASS

//SCENEMANAGER CLASS

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

Scene* SceneManager::getScene()
{
	return this->scene;
}

void SceneManager::loadScene(Scene* s)
{
	delete this->scene;
	this->scene = s;
}