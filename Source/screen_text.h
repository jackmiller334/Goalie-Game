#ifndef SCREEN_TEXT_H
#define SCREEN_TEXT_H

#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>
#include <sstream>

class ScreenText
{
public:
	ScreenText();
	~ScreenText();

	void message(std::string message, sf::Color color, sf::Vector2f position, 
				int size, sf::RenderWindow* window);

	void message(float seconds, sf::Color color, sf::Vector2f position, 
				int size, sf::RenderWindow* window);

private:
	sf::Font font;
	int minutes;
protected:
};

#endif