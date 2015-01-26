#include "Footballer.h"

Footballer::Footballer(sf::RenderWindow* window, Vector2D pos) : Object(window)
{
	this->gameWindow = window;	
	this->position = pos;
	std::cout << "Footballer CREATED" << std::endl;
	sprite.setPosition(position.x,position.y);
	setUpTextures("Assets/Images/footballer.png");
	sprite.setOrigin(5,5);
	srand(time(0));
	loadFootballerTextures();
}

Footballer::~Footballer()
{
	std::cout << " Footballer Deleted" << std::endl;
}


void Footballer::update()
{
	Object::update();
}

void Footballer::swapTextures()
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

void Footballer::loadFootballerTextures()
{
	if(!lookLeft.loadFromFile("Assets/Images/footballerLeft.png"))
	{
		//display error
	}
	
	if(!lookRight.loadFromFile("Assets/Images/footballerRight.png"))
	{
		//display error
	}
}

sf::Sprite Footballer::getSprite()
{
	return this->sprite;
}