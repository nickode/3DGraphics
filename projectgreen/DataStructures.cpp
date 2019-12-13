#include <DataStructures.h>

//WorldEVENT CLASS

WorldEvent::WorldEvent(int et, int kc)
{
	
	this->eventtype = et;
	//this->name = n;
	this->keycode = kc;
}

WorldEvent::~WorldEvent()
{

}

//END WorldEVENT CLASS


//World CLASS

World::World(int w, int h)
{
	window = new RenderWindow(sf::VideoMode(w, h), "Unknown World");
	windowWidth = w;
	windowHeight = h;
	sprites.push_back(new Sprite());
}

World::World(int w, int h, string n)
{
	window = new RenderWindow(sf::VideoMode(w, h), n);
	windowWidth = w;
	windowHeight = h;
	sprites.push_back(new Sprite());
}

World::~World()
{
	delete window;
}

string World::getName()
{
	return name.c_str();
}

void World::setName(string n)
{
	name = n;
	window->setTitle(n);
}

RenderWindow* World::getWindow()
{
	return this->window;
}

vector<WorldEvent*> World::getEvents()
{
	return this->events;
}

void World::addEvent(int et, int kc)
{
	events.push_back(new WorldEvent(et, kc));
}

vector<Texture*> World::getTextures()
{
	return this->textures;
}

void World::addTextureFromFile(string fn)
{
	Texture* text = new Texture();
	text->loadFromFile(fn);
	textures.push_back(text);
}

vector<Sprite*> World::getSprites()
{
	return this->sprites;
}


void World::printDetails()
{
	using std::cout; using std::cin; using std::endl;

	cout << "World: " << name << endl;
	cout << "# of Events: " << events.size() << endl;
	cout << "# of Textures: " << textures.size() << endl;
	cout << "# of Sprites: " << sprites.size() << endl;
}

void World::pollEvent()
{
	Event sfevent;
	while (window->pollEvent(sfevent))
	{
		for (int i = 0; i < events.size(); i++)
		{
			WorldEvent* theevent = events.at(i); 

			if (sfevent.type == theevent->eventtype && sfevent.key.code == theevent->keycode)
			{
				std::cout << "Event type: " << theevent->eventtype << ", Keycode(if applicable): " << theevent->keycode << std::endl;
			}
		}
	}
}

void World::renderWorld()
{

}

//END World CLASS

