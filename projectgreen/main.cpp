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


	Scene admin_console;

	sf::RenderWindow window(sf::VideoMode(800,600), "Hey");
	main_menu.getWindows().push_back(&window);
		

	while ()
	{

		

	}

	return 0;
}
