#ifndef _GAME_H_
#define _GAME_H_

#include <vector>
#include "object_manager.h"
#include "screen_text.h"
#include "scene.h"
#include "highScoreEntry.h"

enum gameState{HOME,PLAY,HIGHSCORE};

class Game
{
public:
	Game(sf::RenderWindow* app);
	~Game();

	void getInput();
	void update();
	void draw();

	void gameLoop();
protected:
private:
	
	sf::RenderWindow* window;
	Scene* scene;
	gameState gameplayState;
	Background* backGround;
	sf::Texture titleTex;
	sf::Sprite  titleSprite;
	Controller homeControl;
	ScreenText name;
};



#endif