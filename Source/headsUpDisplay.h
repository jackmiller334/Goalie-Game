#ifndef HEADS_UP_DISPLAY
#define HEADS_UP_DISPLAY
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>
#include <sstream>

class HeadsUpDisplay
{

public:
	HeadsUpDisplay();
	~HeadsUpDisplay();

	void showTime(int secondsPassed, sf::Color color, sf::Vector2f position,
						 int size, sf::RenderWindow* window);

	void showScore(int score,sf::Color color, sf::Vector2f position,
						 int size, sf::RenderWindow* window);

	void showLives(int score,sf::Color color, sf::Vector2f position,
						 int size, sf::RenderWindow* window); // This should be a temporary function. Lives will be shown by sprites.


private:
	sf::Font font;
	int minutes;

protected:

};

#endif