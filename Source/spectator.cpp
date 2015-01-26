#include "Spectator.h"

Spectator::Spectator(sf::RenderWindow* window, Vector2D pos) : Object(window)
{
	this->gameWindow = window;	
	this->position = pos;
	std::cout << "Spectator CREATED" << std::endl;
	sprite.setPosition(position.x,position.y);
	setUpTextures("Assets/Images/spectator.png");
	sprite.setOrigin(5,5);
	srand(time(0));
	loadSpectatorTextures();
}

Spectator::~Spectator()
{
	std::cout << " Spectator Deleted" << std::endl;
}


void Spectator::update()
{
	Object::update();
}

void Spectator::swapTextures()
{
	randomTexTime = rand() % 5 + 1;

	switch (randomTexTime)
	{
	case 1:
		sprite.setTexture(this->texture);
		break;
	case 2:
		sprite.setTexture(lookLeft);
		break;
	case 3:
		sprite.setTexture(lookRight);
		break;
	}
}

void Spectator::loadSpectatorTextures()
{
	if(!lookLeft.loadFromFile("Assets/Images/SpectatorLeft.png"))
	{
		//display error
	}
	
	if(!lookRight.loadFromFile("Assets/Images/SpectatorRight.png"))
	{
		//display error
	}
}

sf::Sprite Spectator::getSprite()
{
	return this->sprite;
}