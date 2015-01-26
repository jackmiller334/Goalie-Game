#include "goalie.h"

Goalie::Goalie(sf::RenderWindow* window, Vector2D pos) : Object(window)
{
	this->gameWindow = window;
	this->position = pos;
	std::cout << "GOALIE CREATED" << std::endl;
	sprite.setPosition(position.x,position.y);
	setUpTextures("Assets/Images/goalie.png");

	ballBox.minX = sprite.getPosition().x - 2;
	ballBox.maxX = sprite.getPosition().x + sprite.getTextureRect().width + 2;
	ballBox.minY = sprite.getPosition().y + sprite.getTextureRect().height / 2;
	ballBox.maxY = sprite.getPosition().y + sprite.getTextureRect().height + 10;
}

Goalie::~Goalie()
{
}

void Goalie::goalieInput()
{
	//Keyboard Inputs
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
    position.x -= 3.0f;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
	{
    position.x += 3.0f;
	}

	if(controller1.getLeftJoyStickDirection(0) == LEFT)
	{
	position.x -= 3.0f;
	}
	
	if(controller1.getLeftJoyStickDirection(0) == RIGHT)
	{
	position.x += 3.0f;
	}
	
}

void Goalie::update()
{
	Object::update();

	ballBox.minX = sprite.getPosition().x - 10;
	ballBox.maxX = sprite.getPosition().x + sprite.getTextureRect().width + 10;
	ballBox.minY = sprite.getPosition().y + 2;
	ballBox.maxY = sprite.getPosition().y + sprite.getTextureRect().height;
}