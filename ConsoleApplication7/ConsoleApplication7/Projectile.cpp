#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "Projectile.h"
#define PI 3.14159265
Projectile::Projectile(float posXIn, float posYIn, std::string spriteFileName, sf::Vector2f move) :EntityObject(posXIn,posYIn,spriteFileName)
{
	/*setPosition(posXIn, posYIn);
	spriteTexture.loadFromFile(spriteFileName);
	setTexture(spriteTexture);*/
	//EntityObject(posXIn, posYIn, spriteFileName);
	int length = 20;
	int width = 4;
	setTextureRect(sf::IntRect(0, 0, width, length));
	setOrigin(width/2, length/2);
	movement = move;
	setMovement(move);
}
void Projectile::incr(){
	move(movement.x, movement.y);
	
}
void Projectile::setMovement(sf::Vector2f move){
	movement = move;
	double angle = (atan(movement.y / movement.x) * 180 / PI) + 90;
	if (movement.x < 0){
		angle += 180;
	}
	//std::cout << angle << std::endl;
	//std::cout << movement.x << "," << movement.y << std::endl;
	//std::cout << angle << std::endl;
	//setOrigin(5, 25);
	setRotation(angle);
}
sf::Vector2f Projectile::getMovement(){
	return movement;
}