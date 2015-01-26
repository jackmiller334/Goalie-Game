#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <string>
#include <SFML\Graphics.hpp>
#include <iostream>

class Background
{
public:
	Background(std::string filePath);
	~Background();

	void draw(sf::RenderWindow* gameWindow);
protected:
	sf::Texture texture;
	sf::Sprite backSprite;

};

#endif