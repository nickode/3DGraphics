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
	Scene main_menu;
	Scene game;

	admin_console.setName("Admin Console");
	admin_console.getWindows().push_back(new RenderWindow(sf::VideoMode(800, 600), "Admin Console"));

	main_menu.setName("Main Menu");
	main_menu.getWindows().push_back(new RenderWindow(sf::VideoMode(800, 600), "Main Menu"));

	game.setName("Game World");

	SceneManager scenemanager;
	scenemanager.getScenes().push_back(&admin_console);
	scenemanager.getScenes().push_back(&main_menu);
	scenemanager.getScenes().push_back(&game);

	scenemanager.loadNewScene();

	while (scenemanager.getCurrScene()->getWindows().at(0)->isOpen())
	{

		

	}

	return 0;
}
