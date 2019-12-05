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

class Scene
{
private:
	
	string name;

	vector<RenderWindow*> windows;
	vector<Event*> events;
	vector<Texture*> textures;
	vector<Sprite*> sprites;
public:
	Scene();
	~Scene();

	string getName();
	void setName(string n);

	vector<RenderWindow*> getWindows();
	vector<Event*> getEvents();
	vector<Texture*> getTextures();
	vector<Sprite*> getSprites();

	void printDetails();
};

class SceneManager
{
private:
	Scene* curr_scene;
	vector<Scene*> scenes;
public:
	SceneManager();
	~SceneManager();

	vector<Scene*> getSceneList();
	void addScene(Scene* s);

	Scene* getCurrScene();
	void loadNewScene();
	void loadNewScene(int id);
};