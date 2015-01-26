#ifndef BALL_H
#define BALL_H

#include "object.h"
#include "aabb.h"
class Ball : public Object
{
public:
	Ball(sf::RenderWindow* window, Vector2D pos);
	~Ball();

	//virtual void setPosition(Vector2D position);
	sf::Sprite getSprite();

	virtual	void update();
	void resetBallSpeed();
	bool collidesWithBallBox(AABB ballBox);
	bool goal();
};

#endif 