#include <SFML/Graphics.hpp>
#include <DataStructures.h>
#include <fstream>
#include <iostream>

int main()
{
	Scene adminconsole(1024, 1024);
	adminconsole.setName("Admin Console");
	adminconsole.addTextureFromFile("sandystone.png");

	Texture t = *adminconsole.getTextures().at(0);
	adminconsole.getSprites().at(0)->setTexture(t);
	
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::W);
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::A);
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::S);
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::D);

	while (adminconsole.getWindow()->isOpen())
	{
		adminconsole.getWindow()->clear();
		for (int y = 0; y < 32; y++)
		{
			for (int x = 0; x < 32; x++)
			{
				sf::Sprite sprt;
				sprt.setTexture(t);
				sprt.setScale(0.015625, 0.015625);
				sprt.setPosition(32*x,32*y);
				sprt.setRotation(45);
				adminconsole.getWindow()->draw(sprt);
			}
		}
		adminconsole.pollEvent();
		adminconsole.getWindow()->display();

	}

	return 0;
}
