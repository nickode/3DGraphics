#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using std::vector;
using sf::RenderWindow;
using sf::Event;
using sf::Texture;
using sf::Sprite;

class Scene
{
private:
	
	vector<RenderWindow> windows;
	vector<Event> events;
	vector<Texture> textures;
	vector<Sprite> sprites;
public:
	Scene();
	~Scene();

	vector<RenderWindow> getWindows();
	vector<Event> getEvents();
	vector<Texture> getTextures();
	vector<Sprite> getSprites();
};