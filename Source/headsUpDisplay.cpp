#include "headsUpDisplay.h"

HeadsUpDisplay::HeadsUpDisplay()
{
	if(!font.loadFromFile("Fonts/score.ttf"))
	{
		std::cout<<"Font not found"<<std::endl;
	}
	else
	{
		font.loadFromFile("Fonts/score.ttf");
	}
}


void HeadsUpDisplay::showTime(int secondsPassed, sf::Color color, sf::Vector2f position,
						 int size, sf::RenderWindow* window)
{
	std::stringstream timeTaken;
	std::string timeNotice;
	sf::Text display;

	timeTaken << "Time Taken : " << secondsPassed;
	timeNotice = timeTaken.str();
	display.setFont(font);
	display.setString(timeNotice);
	display.setColor(color);
	display.setPosition(position.x,position.y);
	display.setCharacterSize(size);

	window->pushGLStates();
	window->draw(display);
	window->popGLStates();
}

void HeadsUpDisplay::showScore(int playerScore, sf::Color color, sf::Vector2f position,
						 int size, sf::RenderWindow* window)
{
	std::stringstream score;
	std::string scoreDisplay;
	sf::Text display;

	score << "SCORE : " << playerScore;
	scoreDisplay = score.str();
	display.setFont(font);
	display.setString(scoreDisplay);
	display.setColor(color);
	display.setPosition(position.x,position.y);
	display.setCharacterSize(size);

	window->draw(display);

}


void HeadsUpDisplay::showLives(int playerLives, sf::Color color, sf::Vector2f position,
						 int size, sf::RenderWindow* window)
{
	std::stringstream lives;
	std::string livesDisplay;
	sf::Text display;

	lives << "LIVES : " << playerLives;
	livesDisplay = lives.str();
	display.setFont(font);
	display.setString(livesDisplay);
	display.setColor(color);
	display.setPosition(position.x,position.y);
	display.setCharacterSize(size);

	window->draw(display);

}


HeadsUpDisplay::~HeadsUpDisplay()
{

}
