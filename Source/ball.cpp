#include "ball.h"

Ball::Ball(sf::RenderWindow* window, Vector2D pos) : Object(window)
{
	this->gameWindow = window;	
	this->position = pos;
	std::cout << "ball CREATED" << std::endl;
	sprite.setPosition(position.x,position.y);
	setUpTextures("Assets/Images/ball.png");
	sprite.setOrigin(5,5);
	direction.x = 0;
	direction.y = -4;
}

Ball::~Ball()
{
	std::cout << " Ball Deleted" << std::endl;
}


void Ball::update()
{
	Object::update();
	position.x += direction.x;
	position.y += direction.y;
	sprite.rotate(2.4f);
}

bool Ball::collidesWithBallBox(AABB ballBox)
{
	if((position.x <= ballBox.maxX) && (position.x >= ballBox.minX) && (position.y <= ballBox.maxY) && (position.y >= ballBox.minY))
	{
		return true;
	}
	else 
		return false;
}

bool Ball::goal()
{
	if((position.x >= 205) && (position.x <= 358) && (position.y <= 80))
	{
		return true;
	}
	return false;
}

sf::Sprite Ball::getSprite()
{
	return this->sprite;
}