#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
/*This is a EntityObject, the base class from which all other objects are derived
  It needs a position,image and collision data*/
class EntityObject : public sf::Sprite
{
protected:
	float posX;
	float posY;
	sf::Texture spriteTexture;
public:
	EntityObject();
	EntityObject(float posX, float posY,std::string spriteFileName);
	float getPosX(){ return posX; };
	float getPosY(){ return posY; };
};