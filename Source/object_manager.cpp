#include "object_manager.h"

ObjectManager::ObjectManager()
{
	std::cout << "ObjectManager Created" << std::endl;
}

ObjectManager* ObjectManager::instance()
{
	static ObjectManager instance;
	return &instance;
}

ObjectManager::~ObjectManager()
{
	removeAll();
}

bool ObjectManager::addObject(Object* ob)
{
	if(ob == nullptr)
	{
		std::cout << "Error adding entity, nullptr" << std::endl;
		return false;
	}

	if(_gameObjects[ob->getID()] != nullptr)
	{
		std::cout << "Error adding entity with ID " << ob->getID() << std::endl;
		return false;
	}

	_gameObjects[ob->getID()] = std::shared_ptr<Object>(ob);
	std::cout<< "Ob added" << std::endl;
	return true;
}

void ObjectManager::removeObject(int ID)
{
	if(_gameObjects[ID] == nullptr)
	{
		std::cout << "No entity at address" << std::endl;
		return;
	}

	_gameObjects[ID] = nullptr;
	return;
}

void ObjectManager::removeAll()
{
	_gameObjects.clear();
}


int ObjectManager::getObjectCount() const
{
	return _gameObjects.size();
}


std::shared_ptr<Object> ObjectManager::getID(int id)
{
	return _gameObjects.find(id)->second;
}