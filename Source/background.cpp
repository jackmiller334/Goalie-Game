#include "background.h"

Background::Background(std::string filePath)
{
	if(!texture.loadFromFile(filePath))
	{
		std::cout<< "Background not loaded" << std::endl;
	}
	backSprite.setTexture(texture);

}

Background::~Background()
{
	std::cout << "Background Deleted"<< std::endl;
}

void Background::draw(sf::RenderWindow* gameWindow)
{
	gameWindow->draw(backSprite);
}
