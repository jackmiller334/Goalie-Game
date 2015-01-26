#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "SFML\Window\Joystick.hpp"
#include <iostream>

enum direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum buttons
{
	A,
	B,
	X,
	Y,
	LB,
	RB,
	BACK,
	START,
	LSTICK,
	RSTICK,
	LTRIGGERDOWN,
	RTRIGGERDOWN
};

class Controller 
{
public:
	Controller();
	~Controller();

	int getLeftJoyStickDirection(int controllerID);
	int getRightJoyStickDirection(int controllerID);
	int getInputButtons(int controllerID);
	int getDirButtons(int controllerID);
	int getBumpersAndTriggers(int controllerID);
	int getMenuButtons(int controllerID);
	void checkConnected();

	static int controllerID;
private:

};

#endif