#ifndef HIGHSCOREENTRY
#define HIGHSCOREENTRY
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>

class HighScoreEntry
{
public:
	HighScoreEntry();
	~HighScoreEntry();

	void receiveInput();
	void addToHighscoreEntry(char x);


private:
	std::string entry;
	int entryCount;
	bool pressed;
protected:

};

#endif