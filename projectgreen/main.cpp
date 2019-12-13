#include <SFML/Graphics.hpp>
#include <DataStructures.h>
#include <fstream>
#include <iostream>

int main()
{
	World adminconsole(1152, 648);
	adminconsole.setName("Admin Console");
	adminconsole.addTextureFromFile("sandystone.png");
	
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::W);
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::A);
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::S);
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::D);

	

	while (adminconsole.getWindow()->isOpen())
	{
		adminconsole.getWindow()->clear();
		adminconsole.pollEvent();
		for (int y = 0; y < 135; y++)
		{
			for (int x = 0; x < 240; x++)
			{
				
				adminconsole.getWindow()->draw(sprt);
			}
		}
		
		adminconsole.getWindow()->display();

	}

	return 0;
}
