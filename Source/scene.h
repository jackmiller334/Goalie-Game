#ifndef SCENE
#define SCENE

#include <random>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <SFML\Graphics.hpp>
#include "background.h"
#include "goalie.h"
#include "ball.h"
#include "headsUpDisplay.h"
#include <time.h>
#include "footballer.h"
#include "spectator.h"
#include "audio.h"

enum state{BEGIN,PLAYING,WAITING};
//Holds game objects and loads/clears levels
class Scene
{
public:
	Scene(sf::RenderWindow* window);
	~Scene();
	
	void drawScene();
	Goalie* goalie;
	Ball* ball;

	int score;
	int comboCounter;
	int combo;
	void updateScene();
	void loadComboTextures();
	int getPlayerLives();
private:
	int playerLives;
	int goalieBeginMovement;
	int goalieBeginVelocity;
	float ballSpeed;
	void checkCombo();
	void createCrowd();
	void showScore();
	bool waitingForBall;
	void createBall();
	void increaseBallSpeed();
	void resetBallSpeed();
	bool waitForBall(float randomTime);
	
	float randomTime;
	sf::Time timer;
	sf::Clock ballDelay;
	Audio gameSounds;
	sf::RenderWindow* gameWindow;
	Background* background;
	HeadsUpDisplay scoreDisplay;
	sf::Sprite comboSprite;
	state gamestate;
	sf::Texture comboTex1;
	sf::Texture comboTex2;
	sf::Texture comboTex3;
	std::vector<Footballer*> footballers;
	std::vector<Spectator*> spectators;
};

#endif