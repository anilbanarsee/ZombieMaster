#pragma once
#include "Item.h"
#include <SFML\Graphics.hpp>
Item::Item(int posX, int posY, std::string spriteFileName) : EntityObject(posX, posY, spriteFileName)
{
	//Set up general Item stuff here
}
bool Item::inRange(EntityObject object)
{
	//Find out if this item is in range of that object
	return ((posX - object.getPosX()) + (posY - object.getPosY()) <= pickUpRange);
}