#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <memory>
#include "object.h"


class ObjectManager
{
public:
	
	static ObjectManager *instance();
	~ObjectManager();

	bool addObject(Object* ob);
	Object* objectAtID(int ID);

	void removeObject(int ID);
	void removeAll();

	int getObjectCount() const;
	std::shared_ptr<Object> getID(int id);
	void drawAll(sf::RenderWindow* window);

private:

	ObjectManager();
	std::map<int, std::shared_ptr<Object>> _gameObjects;
};

#endif