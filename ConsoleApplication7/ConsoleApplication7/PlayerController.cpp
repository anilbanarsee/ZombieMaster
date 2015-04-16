#include "PlayerController.h"
#include <SFML/Graphics.hpp>
PlayerController::PlayerController()
{
	speed = 0.005;
}
PlayerController::PlayerController(double speedAmount)
{
	speed = speedAmount;
}
//This method moves the player based on the input
void PlayerController::getMovement()
{
	//First check what direction is being pressed down, and add speed in that direction
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

		xSpeed -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){

		xSpeed -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

		xSpeed += speed;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

		xSpeed += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

		ySpeed -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

		ySpeed -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

		ySpeed += speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

		ySpeed += speed;
	}

	//Then we need to check friction and top speed
	if (xSpeed >= 0){
		xSpeed -= friction;
		if (xSpeed < 0){
			xSpeed = 0;
		}
	}
	if (xSpeed <= 0){
		xSpeed += friction;
		if (xSpeed > 0){
			xSpeed = 0;
		}
	}
	if (ySpeed >= 0){
		ySpeed -= friction;
		if (ySpeed < 0){
			ySpeed = 0;
		}
	}
	if (ySpeed <= 0){
		ySpeed += friction;
		if (ySpeed > 0){
			ySpeed = 0;
		}
	}

	if (xSpeed >= topSpeed){
		xSpeed = topSpeed;
	}
	if (xSpeed <= -topSpeed){
		xSpeed = -topSpeed;
	}
	if (ySpeed >= topSpeed){
		ySpeed = topSpeed;
	}
	if (ySpeed <= -topSpeed){
		ySpeed = -topSpeed;
	}

	//Lastly we need to keep the player in the screen/map
}
double PlayerController::getXSpeed()
{
	return xSpeed;
}
double PlayerController::getYSpeed()
{
	return ySpeed;
}