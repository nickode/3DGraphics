#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using sf::RenderWindow;
using sf::Event;
using sf::Texture;
using sf::Sprite;
using std::string;

class WorldEvent
{
public:
	string name;
	int eventtype;
	int keycode;

	WorldEvent(int et, int kc);
	~WorldEvent();
};

class World
{
private:
	string name;
	int windowWidth;
	int windowHeight;
	RenderWindow* window;
	vector<WorldEvent*> events;
	vector<Texture*> textures;
	vector<Sprite*> sprites;
	int viewIndex[240][135];

public:

	World(int w, int h);
	World(int w, int h, string n);
	~World();

	string getName();
	void setName(string n);

	RenderWindow* getWindow();

	vector<WorldEvent*> getEvents();
	void addEvent(int et, int kc);

	vector<Texture*> getTextures();
	void addTextureFromFile(string fn);

	vector<Sprite*> getSprites();

	void printDetails();
	void pollEvent();
	void renderWorld();

};

class Tile
{
private:
	short id;
	string name;
	Texture texture;
	float width;
	float height;
public:
	short getId();
	string getName();
	float getWidth();
	float getHeight();

	void setName();
	void setWidth();
	void setHeight();
};

