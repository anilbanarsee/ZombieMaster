//This is the item class, it is used for any item in the game
#pragma once
#include "EntityObject.h"
#include <SFML\Graphics.hpp>
class Item : public EntityObject
{
protected:
	int pickUpRange = 1;
public:
	Item(int posX, int posY, std::string spriteFileName);
	bool inRange(EntityObject object);
};