#include <SFML/Graphics.hpp>
#include <DataStructures.h>

void pollEvent(sf::Window& window)
{
	sf::Event sfevent;
	while (window.pollEvent(sfevent))
	{
		if (sfevent.type == sf::Event::Closed)
			window.close();
		if (sfevent.type == sf::Event::KeyPressed && sfevent.key.code == sf::Keyboard::Left)
			window.close();

	}
}

int main()
{
	Scene main_menu;


	main_menu->getWindows()->push_back(new RenderWindow(sf::VideoMode(800, 600),"Projectgreen"));
		

	while (true)
	{

		
	
		

		
		window.display();
	}

	return 0;
}

