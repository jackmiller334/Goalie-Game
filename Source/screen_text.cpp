#include "screen_text.h"

ScreenText::ScreenText()
{
	if(!font.loadFromFile("Fonts/ARLRDBD.ttf"))
	{
		std::cout<<"Font not found"<<std::endl;
	}
	else
	{
		font.loadFromFile("Fonts/ARLRDBD.ttf");
	}
}

void ScreenText::message(std::string message, sf::Color color, sf::Vector2f position,
						 int size, sf::RenderWindow* window)
{
	sf::Text text;
	text.setFont(font);
	text.setString(message);
	text.setColor(color);
	text.setPosition(position.x, position.y);
	text.setCharacterSize(size);
	//text.setOrigin(text.getPosition().x/2, text.getPosition().y/2);
	window->pushGLStates();
	window->draw(text);
	window->popGLStates();
}



ScreenText::~ScreenText()
{

}