#include "highScoreEntry.h"

HighScoreEntry::HighScoreEntry()
{
	entryCount = 0;
	entry = "";
	pressed = false;
}

HighScoreEntry::~HighScoreEntry()
{
}

void HighScoreEntry::addToHighscoreEntry(char x)
{
	entry += x;
}

void HighScoreEntry::receiveInput()
{
	

	

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << "A" << std::endl;
	}

}











































































