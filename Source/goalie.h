#ifndef GOALIE_H
#define GOALIE_H

#include "object.h"
#include "aabb.h"
#include "controller.h"
class Goalie : public Object
{
public:
	Goalie(sf::RenderWindow* window, Vector2D pos);
	~Goalie();


	void goalieInput();
	virtual void update();
	AABB ballBox;
	Controller controller1;
};

#endif 