#include <SFML/Graphics.hpp>
#include <DataStructures.h>
#include <fstream>
#include <iostream>

int main()
{
	Scene adminconsole(1000, 1000);
	adminconsole.setName("Admin Console");
	
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::W);
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::A);
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::S);
	adminconsole.addEvent(sf::Event::KeyPressed, sf::Keyboard::D);


	while (adminconsole.getWindow()->isOpen())
	{
		for (int y = 0; y < adminconsole.rowcolnum; y++)
		{
			for (int x = 0; x < adminconsole.rowcolnum; x++)
			{
				adminconsole.getWindow()->draw(adminconsole.getRooms().at(0)->getTile(x,y));
			}
		}
		adminconsole.pollEvent();
		adminconsole.getWindow()->display();

	}

	return 0;
}
