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

class SceneEvent
{
public:
	string name;
	int eventtype;
	int keycode;

	SceneEvent(int et, int kc);
	~SceneEvent();
};

class Room
{
private:
	int tilewidth;
	int tileheight;
	sf::RectangleShape* grid[25][25];
public:
	Room(int w, int h, int rcn);
	~Room();

	int getTileWidth();
	int getTileHeight();
	const sf::RectangleShape& getTile(int i, int j);
};

class Scene
{
private:
	string name;
	RenderWindow* window;
	vector<SceneEvent*> events;
	vector<Texture> textures;
	vector<Sprite> sprites;
	vector<Room*> rooms;

public:
	const int rowcolnum = 25;

	Scene(int w, int h);
	Scene(int w, int h, string n);
	~Scene();

	string getName();
	void setName(string n);

	RenderWindow* getWindow();

	vector<SceneEvent*> getEvents();
	void addEvent(int et, int kc);
	vector<Texture> getTextures();
	void addTexture();
	vector<Sprite> getSprites();
	void addSprite();
	vector<Room*> getRooms();
	void addRoom();

	void printDetails();
	void pollEvent();

};

class SceneManager
{
private:
	Scene* curr_scene;
	vector<Scene> scenes;
public:
	SceneManager();
	~SceneManager();

	vector<Scene> getScenes();
	void addScene(Scene s);

	Scene* getCurrScene();
	void loadNewScene();
	void loadNewScene(int id);
};

