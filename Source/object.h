#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "vector2D.h"

class Object
{
public:
	Object();
	Object(sf::RenderWindow* window);
	virtual void draw();

	int getID() const;
	
	virtual void setUpTextures(std::string filePath);
	void setPosition(Vector2D position);
	void setDirection(Vector2D direction);

	Vector2D getPosition();
	Vector2D getDirection();

	virtual void update();
	sf::Sprite getSprite();
	virtual ~Object();
	virtual void drawDebug();

private: //Only accesible by the base class (Child classes have overided function with own ptr to RenderWindow)
	
	void setID();
	int objectID;
	static int nextValidID;

protected: //To be used by child classes
	sf::RenderWindow* gameWindow;
	sf::Texture texture;
	sf::Sprite sprite;
	std::string filePath;
	Vector2D position;
	Vector2D direction;
};

#endif