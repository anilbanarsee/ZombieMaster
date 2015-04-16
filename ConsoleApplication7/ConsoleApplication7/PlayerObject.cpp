#pragma once
#include "PlayerObject.h"
#include <string>;
PlayerObject::PlayerObject(int posX, int posY, std::string spriteFileName) : EntityObject(posX,posY,spriteFileName)
{
	//TO-DO: set playerObject variables
}

void PlayerObject::getMovement()
{
	controller.getMovement();
	move(controller.getXSpeed(), controller.getYSpeed());
}