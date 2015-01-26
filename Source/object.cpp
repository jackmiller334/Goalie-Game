#include "object.h"
#include "object_manager.h"

Object::Object()
{
	std::cout<<"default constructor"<<std::endl;
}

int Object::nextValidID = 0;

Object::Object(sf::RenderWindow* window)
{
	gameWindow = window;
	objectID = 0;
	setID();
	std::cout<<"custom constructor"<<std::endl;
}

void Object::draw()
{
	gameWindow->draw(sprite);
}

void Object::update()
{
	sprite.setPosition(position.x,position.y);
}

int Object::getID() const
{
	return objectID;
}

void Object::setID()
{
	++nextValidID;
	objectID = nextValidID;
	ObjectManager::instance()->addObject(this);
}

void Object::setUpTextures(std::string filePath)
{
	if(!texture.loadFromFile(filePath))
	{
		std::cout<< "notloaded" << std::endl;
	}
	sprite.setTexture(texture);
	std::cout<<"SetUp Called" << std::endl;
}

sf::Sprite Object::getSprite()
{
	return sprite;
}

Vector2D Object::getPosition()
{
	return position;
}

Vector2D Object::getDirection()
{
	return direction;
}

void Object::setPosition(Vector2D pos)
{
	position = pos;
}

void Object::setDirection(Vector2D dir)
{
	direction = dir;
}

Object::~Object()
{
	std::cout<< "Object Deleted" << std::endl;
}

void Object::drawDebug(){}