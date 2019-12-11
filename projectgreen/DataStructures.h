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

class Scene
{
private:
	string name;
	int width;
	int height;
	RenderWindow* window;
	vector<SceneEvent*> events;
	vector<Texture*> textures;
	vector<Sprite*> sprites;
	int viewIndex[30][30];

public:

	Scene(int w, int h);
	Scene(int w, int h, string n);
	~Scene();

	string getName();
	void setName(string n);

	RenderWindow* getWindow();

	vector<SceneEvent*> getEvents();
	void addEvent(int et, int kc);

	vector<Texture*> getTextures();
	void addTextureFromFile(string fn);

	vector<Sprite*> getSprites();

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

