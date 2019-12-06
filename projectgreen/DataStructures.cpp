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

vector<Scene*> SceneManager::getScenes()
{
	return scenes;
}

void SceneManager::addScene(Scene* s)
{
	scenes.push_back(s);
}

Scene* SceneManager::getCurrScene()
{
	return this->curr_scene;
}

void SceneManager::loadNewScene()
{
	using std::cout; using std::cin; using std::endl;

	cout << "Select a scene to load..." << endl;
	for (int i = 0; i < scenes.size(); i++)
	{
		cout << i+". " <<  scenes.at(i)->getName() << endl;
	}
	int choice;
	cin >> choice;
	
	this->curr_scene = scenes.at(choice);
}

void SceneManager::loadNewScene(int i)
{
	this->curr_scene = scenes.at(i);
}
