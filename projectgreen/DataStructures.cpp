#include <DataStructures.h>

//SCENEEVENT CLASS

SceneEvent::SceneEvent(int et, int kc)
{
	
	this->eventtype = et;
	//this->name = n;
	this->keycode = kc;
}

SceneEvent::~SceneEvent()
{

}

//END SCENEEVENT CLASS


//SCENE CLASS

Scene::Scene(int w, int h)
{
	window = new RenderWindow(sf::VideoMode(w, h), "Unknown scene");
	rooms.push_back(new Room(w, h, rowcolnum));
}

Scene::Scene(int w, int h, string n)
{
	window = new RenderWindow(sf::VideoMode(w, h), n);
	rooms.push_back(new Room(w, h, rowcolnum));
}

Scene::~Scene()
{
	delete window;
}

string Scene::getName()
{
	return name.c_str();
}

void Scene::setName(string n)
{
	name = n;
	window->setTitle(n);
}

RenderWindow* Scene::getWindow()
{
	return this->window;
}

vector<SceneEvent*> Scene::getEvents()
{
	return this->events;
}

void Scene::addEvent(int et, int kc)
{
	events.push_back(new SceneEvent(et, kc));
}

vector<Texture> Scene::getTextures()
{
	return this->textures;
}

vector<Sprite> Scene::getSprites()
{
	return this->sprites;
}

vector<Room*> Scene::getRooms()
{
	return this->rooms;
}

void Scene::addRoom()
{
	rooms.push_back(new Room(800,800, rowcolnum));
}

void Scene::printDetails()
{
	using std::cout; using std::cin; using std::endl;

	cout << "Scene: " << name << endl;
	cout << "# of Events: " << events.size() << endl;
	cout << "# of Textures: " << textures.size() << endl;
	cout << "# of Sprites: " << sprites.size() << endl;
}

void Scene::pollEvent()
{
	Event sfevent;
	while (window->pollEvent(sfevent))
	{
		for (int i = 0; i < events.size(); i++)
		{
			SceneEvent* theevent = events.at(i); 

			if (sfevent.type == theevent->eventtype && sfevent.key.code == theevent->keycode)
			{
				std::cout << "Event type: " << theevent->eventtype << ", Keycode(if applicable): " << theevent->keycode << std::endl;
			}
		}
	}
}



//END SCENE CLASS

//SCENEMANAGER CLASS

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

vector<Scene> SceneManager::getScenes()
{
	return scenes;
}

void SceneManager::addScene(Scene s)
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
		cout << i+". " <<  scenes.at(i).getName() << endl;
	}
	int choice;
	cin >> choice;
	
	this->curr_scene = &scenes.at(choice);
}

void SceneManager::loadNewScene(int i)
{
	this->curr_scene = &scenes.at(i);
}

//END SCENEMANAGER CLASS

//ROOM CLASS

Room::Room(int w, int h, int rcn)
{
	tilewidth = w/rcn;
	tileheight = h/rcn;
	for (int x = 0; x < rcn; x++)
	{
		for (int y = 0; y < rcn; y++)
		{
			sf::RectangleShape* tile = new sf::RectangleShape();
			tile->setPosition(sf::Vector2f(tilewidth * x, tileheight * y));
			tile->setSize(sf::Vector2f(tilewidth, tileheight));
			tile->setFillColor(sf::Color(x+y,x+y,x+y));

			grid[x][y] = tile;

		}
	}
}

Room::~Room()
{

}

int Room::getTileWidth()
{
	return tilewidth;
}

int Room::getTileHeight()
{
	return tileheight;
}

const sf::RectangleShape& Room::getTile(int i, int j)
{
	return *grid[i][j];
}

//END ROOM CLASS
