#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
   sf::RenderWindow window(sf::VideoMode(600, 800), "Goalie!");

	Game* game = new Game(&window);
	window.setFramerateLimit(60);

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255,255,255));

		game->gameLoop();
		
        window.display();
    }

	delete game;
	game = nullptr;


    return 0;
}