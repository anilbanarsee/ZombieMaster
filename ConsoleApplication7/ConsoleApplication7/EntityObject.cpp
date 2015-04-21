#pragma once
#include <SFML/Graphics.hpp>
#include "EntityObject.h"
//An empty constructor
EntityObject::EntityObject()
{

}

//This creates a new EntityObject with a position and image

EntityObject::EntityObject(float posXIn, float posYIn, std::string spriteFileName)
{
	setPosition(posXIn, posYIn);
	spriteTexture.loadFromFile(spriteFileName);
	setTexture(spriteTexture);
}