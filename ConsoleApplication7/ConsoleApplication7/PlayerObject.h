#pragma once
#include "EntityObject.h"
#include "PlayerController.h"
//This class represents a player Object
//Aka a player character
class PlayerObject : EntityObject
{
private:
	PlayerController controller;
public:
	PlayerObject(int posX,int posY, std::string spriteFileName);

};