#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include "EntityObject.h"

class Projectile : public EntityObject
{
public:
	sf::Vector2f movement;
	Projectile(float posX, float posY, std::string spriteFileName, sf::Vector2f);
	void incr();
};