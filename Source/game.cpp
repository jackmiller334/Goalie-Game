#include "game.h"

Game::Game(sf::RenderWindow* app) : window(app)
{
	backGround = new Background("Assets/Images/background.png");
	if(!titleTex.loadFromFile("Assets/Images/titleText.png"))
	{
		//display error
	}
	titleSprite.setTexture(titleTex);
	titleSprite.setPosition(120,400);
	gameplayState = HOME;
}

Game::~Game()
{
	if(gameplayState == PLAY)
	{
	//ObjectManager::instance()->removeAll();
	delete scene;
	scene = nullptr;
	}
}

void Game::getInput()
{
	scene->goalie->goalieInput();
}

void Game::update()
{
	scene->updateScene();
}

void Game::draw()
{
	scene->drawScene();
}

void Game::gameLoop()
{
	backGround->draw(window);
	if(gameplayState == PLAY)
	{
		if(scene->getPlayerLives() != 0)
		{
			getInput();
			update();
			draw();
		}
		else
		{
		delete scene;
		scene = nullptr;
		gameplayState = HIGHSCORE;

		//Change state to highscore state
		//

		}
	}


	else if(gameplayState == HIGHSCORE)
	{
		HighScoreEntry highScore;
		highScore.receiveInput();
	}

	else
	{
		window->draw(titleSprite);
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) || (homeControl.getInputButtons(0) == A))
		{
			scene = new Scene(window);
			gameplayState = PLAY;
		}
	}

	name.message("Jack Miller",sf::Color::White,sf::Vector2f(0,771),20,window);
	
}