#ifndef SPECTATOR_H
#define SPECTATOR_H

#include "object.h"
#include "aabb.h"
class Spectator : public Object
{
public:
	Spectator(sf::RenderWindow* window, Vector2D pos);
	~Spectator();

	//virtual void setPosition(Vector2D position);
	sf::Sprite getSprite();
	void loadSpectatorTextures();
	virtual	void update();
	void swapTextures();
	sf::Time spectatorTime;
	sf::Clock textureSwap;

	sf::Texture lookRight;
	sf::Texture lookLeft;

	int randomTexTime;
};

#endif 