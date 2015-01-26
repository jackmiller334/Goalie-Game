#include "scene.h"

Scene::Scene(sf::RenderWindow* window) : gameWindow(window)
{
	std::cout << "SceneManager Created" << std::endl;
	
	goalie = new Goalie(gameWindow,Vector2D(285,300));

	for(int i = 400; i < 480; i+=20)
	{
	Footballer* footballer = new Footballer(gameWindow,Vector2D(i,350));
	footballers.push_back(footballer);
	}

	createCrowd();
	goalieBeginMovement = 2.5;
	playerLives = 3;
	score = 0;
	combo = 1;
	comboCounter = 1;
	ballSpeed = -4; // Speed at which the ball flies at the goal 
	loadComboTextures();
	comboSprite.setPosition(560,150);
	comboSprite.setScale(1.5f,1.5f);
	checkCombo(); // used at constructor to initialise combo sprite

	gamestate = BEGIN;
}

void Scene::updateScene()
{
	if(gamestate == BEGIN)
	{
		goalie->setPosition(Vector2D(goalie->getPosition().x,goalie->getPosition().y - goalieBeginMovement));

		if(goalie->getPosition().y <=110)
		{
			createBall();
			gamestate = PLAYING;
		}
	}

	if(gamestate == PLAYING) {

		ball->update();

		if(ball->collidesWithBallBox(goalie->ballBox)) {
			cout << "combo : " << combo << endl;
			cout << "combo counter : " << comboCounter << endl;
			score += combo;
			comboCounter++;
			checkCombo();
			ballDelay.restart();
			increaseBallSpeed();
			gamestate = WAITING;
		}


		//In case the ball misses the goal completely.
		if(ball->getPosition().y < 10) {
			ballDelay.restart();
			gamestate = WAITING;		
		}

		if(ball->goal()) {
			comboCounter = 1;
			playerLives--;
			checkCombo();
			ballDelay.restart();
			resetBallSpeed();
			gamestate = WAITING;
		}
	}

	if(gamestate == WAITING) {
		ball->update();
		goalie->update();
		srand(time(0));
		randomTime = rand() % 2 + 0;
		if(waitForBall(randomTime))
		{
				createBall();
				gamestate = PLAYING;
		}
	}

	goalie->update();
}

void Scene::drawScene()
{
	goalie->draw();

	if(gamestate == PLAYING)
		{
		ball->draw();
		}

	showScore();
	gameWindow->draw(comboSprite);

	for(auto i = footballers.begin(); i != footballers.end(); ++i)
	{
		(*i)->draw();
	}

	for(auto i = spectators.begin(); i != spectators.end(); ++i)
	{
		(*i)->draw();
	}

}

void Scene::showScore()
{
	scoreDisplay.showScore(score,sf::Color::Black,sf::Vector2f(470,180),22,gameWindow);
	scoreDisplay.showLives(playerLives,sf::Color::Black,sf::Vector2f(470,210),22,gameWindow);
}

void Scene::checkCombo()
{
	cout << "CHECKING COMBO " << endl;
	switch (comboCounter)
	{
	case 1:
		combo = 1;
		comboSprite.setTexture(comboTex1);
		break;
	case 5:
		combo = 2;
		comboSprite.setTexture(comboTex2);
		break;
	case 10:
		combo = 3;
		comboSprite.setTexture(comboTex3);
		break;
	}
}

bool Scene::waitForBall(float randomTime)
{

	timer = ballDelay.getElapsedTime();	

	if(timer.asSeconds() > randomTime)
	{

	for(auto i = footballers.begin(); i != footballers.end(); ++i)
	{
		(*i)->swapTextures();
	}

	for(auto i = spectators.begin(); i != spectators.end(); ++i)
	{
		(*i)->swapTextures();
	}

	return true;
	}
	return false;
}

void Scene::createBall()
{
	srand(time(0));
	ball = new Ball(gameWindow,Vector2D(300,500));
	float randX = rand() % 20 + -10;
	randX /= 10;
	std::cout << randX << std::endl;

	ball->setDirection(Vector2D(randX, ballSpeed));
	gameSounds.playKick1();
}


void Scene::loadComboTextures()
{
	if(!comboTex1.loadFromFile("Assets/Images/1x.png"))
	{
		//display error
	}
	
	if(!comboTex2.loadFromFile("Assets/Images/2x.png"))
	{
		//display error
	}
	if(!comboTex3.loadFromFile("Assets/Images/3x.png"))
	{
		//display error
	}

}


int Scene::getPlayerLives()
{
	return playerLives;
}

void Scene::createCrowd()
{
		for(int i = 0; i < 600; i += 15)
	{
			Spectator* spectator = new Spectator(gameWindow,Vector2D(i,5));
			spectators.push_back(spectator);
	}

	for(int i = -7; i < 600; i += 15)
	{
			Spectator* spectator = new Spectator(gameWindow,Vector2D(i,20));
			spectators.push_back(spectator);
	}
}

void Scene::resetBallSpeed()
{
	ballSpeed = -4;
}

void Scene::increaseBallSpeed()
{
	if(ballSpeed > -10)
	{
		ballSpeed -= 0.5;
	}
	else 
	{
		ballSpeed = -10;
	}
}

//destructor
Scene::~Scene()
{

}