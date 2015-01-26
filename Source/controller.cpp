#include "controller.h"

Controller::Controller()
{
	
}

int Controller::getLeftJoyStickDirection(int controllerID)
{
	float x, y;
	sf::Joystick::update();

	x = sf::Joystick::getAxisPosition(controllerID, sf::Joystick::X);
	y = sf::Joystick::getAxisPosition(controllerID, sf::Joystick::Y);

	if(y >= -100 && y < -50)
	{
	//	std::cout << " UP " << std::endl;
		return UP;

	}
	if(y <= 100 && y > 50)
	{
	//	std::cout << " DOWN " << std::endl;
		return DOWN;

	}
	if(x <= 100 && x > 50)
	{
	//	std::cout << " RIGHT " << std::endl;
		return RIGHT;
		
	}
	if(x >= -100 && x < -50)
	{
	//	std::cout << " LEFT " << std::endl;
		return LEFT;
	}


}

int Controller::getRightJoyStickDirection(int controllerID)
{
	float x, y;
	sf::Joystick::update();
	x = sf::Joystick::getAxisPosition(controllerID, sf::Joystick::U);
	y = sf::Joystick::getAxisPosition(controllerID, sf::Joystick::R);

	if(y >= -100 && y < -50)
	{
		return UP;
	}
	if(y <= 100 && y > 50)
	{
		return DOWN;
	}
	if(x <= 100 && x > 50)
	{
		return RIGHT;
	}
	if(x >= -100 && x < -50)
	{
		return LEFT;
	}
}

int Controller::getInputButtons(int controllerID)
{
	sf::Joystick::update();
	if(sf::Joystick::isButtonPressed(controllerID, 0))
	{
		return A;
	}
	if(sf::Joystick::isButtonPressed(controllerID, 1))
	{
		return B;
	}
	if(sf::Joystick::isButtonPressed(controllerID, 2))
	{
		return X;
	}
	if(sf::Joystick::isButtonPressed(controllerID, 3))
	{
		return Y;
	}
}

int Controller::getDirButtons(int controllerID)
{
	float x, y;
	sf::Joystick::update();
	x = sf::Joystick::getAxisPosition(controllerID, sf::Joystick::PovY);
	y = sf::Joystick::getAxisPosition(controllerID, sf::Joystick::PovX);
	if(y >= 1 && y <= 100)
	{
		return UP;
	}
	if(y <= -1 && y >= -100)
	{
		return DOWN;
	}
	if(x >= 1 && x >= 100)
	{
		return RIGHT;
	}
	if(x <= -1 && x <= -100)
	{
		return LEFT;
	}
}

int Controller::getBumpersAndTriggers(int controllerID)
{
	float z;
	sf::Joystick::update();
	z = sf::Joystick::getAxisPosition(controllerID, sf::Joystick::Z);

	if(sf::Joystick::isButtonPressed(controllerID, 4))
	{
		return LB;
	}
	if(sf::Joystick::isButtonPressed(controllerID, 5))
	{
		return RB;
	}
	if(z >= 1 && z <= 100)
	{
		return LTRIGGERDOWN;
	}
	if(z <= -1 && z >= -100)
	{
		return RTRIGGERDOWN;
	}

}

int Controller::getMenuButtons(int controllerID)
{
	sf::Joystick::update();
	if(sf::Joystick::isButtonPressed(controllerID, 6))
	{
		return BACK;
	}
	if(sf::Joystick::isButtonPressed(controllerID, 7))
	{
		return START;
	}
	if(sf::Joystick::isButtonPressed(controllerID, 8))
	{
		return LSTICK;
	}
	if(sf::Joystick::isButtonPressed(controllerID, 9))
	{
		return RSTICK;
	}
}

void Controller::checkConnected()
{
	if(sf::Joystick::isConnected(0))
	{
		std::cout<<"Controller 1 Connected"<<std::endl;
	}
	else
	{
		std::cout<<"Controller 1 not connected"<<std::endl;
	}
	if(sf::Joystick::isConnected(1))
	{
		std::cout<<"Controller 2 Connected"<<std::endl;
	}
	else
	{
		std::cout<<"Controller 2 not connected"<<std::endl;
	}
	if(sf::Joystick::isConnected(2))
	{
		std::cout<<"Controller 3 Connected"<<std::endl;
	}
	else
	{
		std::cout<<"Controller 3 not connected"<<std::endl;
	}
	if(sf::Joystick::isConnected(3))
	{
		std::cout<<"Controller 4 Connected"<<std::endl;
	}
	else
	{
		std::cout<<"Controller 4 not connected"<<std::endl;
	}
}

Controller::~Controller()
{

}

