#ifndef FOOTBALLER_H
#define FOOTBALLER_H

#include "object.h"
#include "aabb.h"
class Footballer : public Object
{
public:
	Footballer(sf::RenderWindow* window, Vector2D pos);
	~Footballer();

	//virtual void setPosition(Vector2D position);
	sf::Sprite getSprite();
	void loadFootballerTextures();
	virtual	void update();
	void swapTextures();
	sf::Time footballerTime;
	sf::Clock textureSwap;

	sf::Texture lookRight;
	sf::Texture lookLeft;

	int randomTexTime;
};

#endif 