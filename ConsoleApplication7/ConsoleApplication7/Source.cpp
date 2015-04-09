#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cmath>
 
using sf::Vector2;

bool hit(Vector2<float> v1, Vector2<float> v2, double r1, double r2){
	double comR = r1 + r2;
	
	double xpos1 = v1.x;
	double xpos2 = v2.x;

	double ypos1 = v1.y;
	double ypos2 = v2.y;

	double diffX = xpos1 - xpos2;
	double diffY = ypos1 - ypos2;

	diffX = diffX*diffX;
	diffY = diffY*diffY;

	double distance = sqrt(diffX + diffY);

	if (comR >= distance){
		return true;
	}
	return false;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 800), "SFML works!");
	sf::CircleShape shape(20.f);
	sf::CircleShape enemy(20.f);

	double xspeed = 0;
	double yspeed = 0;
	double enemyPower = 0.01;

	double enemyXSpeed = enemyPower;
	double enemyYSpeed = enemyPower;

	double topspeed = 0.1;
	double power = 0.03;
	
	double friction = 0.03;
	double acceleration = 0.05;
	bool leftKeyDown = false;
	bool rightKeyDown = false;
	bool upKeyDown = false;
	bool downKeyDown = false;

	int maxspeed = 8;

	shape.setFillColor(sf::Color::Green);
	enemy.setFillColor(sf::Color::Red);

	
	enemy.setPosition(200, 200);
	shape.setPosition(300, 400);
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			xspeed += -power;


		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			xspeed += -power;


		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			xspeed += power;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			xspeed += power;

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			yspeed += -power;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			yspeed += -power;

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			yspeed += power;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			yspeed += power;

		}
		
		
		sf::Vector2<float> c = enemy.getPosition();
		double r = enemy.getRadius();
		double xpos = c.x + r;
		double ypos = c.y + r;

		if (xpos+r > 600 || xpos-r <0){
			enemyXSpeed = -enemyXSpeed;
		}
		if (ypos+r > 800 || ypos-r <0){
			enemyYSpeed = -enemyYSpeed;
		}
		
		c = shape.getPosition();
		r = shape.getRadius();
		double xpos2 = c.x + shape.getRadius();
	    double ypos2 = c.y + shape.getRadius();

		if (xpos2+r >= 600 && xspeed > 0){
			xspeed = 0;
			//std::cout << "ALERT" << std::endl;
		}
		if (xpos2-r <= 0 && xspeed < 0){
			xspeed = 0;
		}
		if (ypos2+r >= 800 && yspeed > 0){
			yspeed = 0;
		}
		if (ypos2-r <= 0 && yspeed < 0){
			yspeed = 0;
		}
		//std::cout << c.x << std::endl;
		//std::cout << xspeed << std::endl;

		//std::cout << xspeed << std::endl;
		//std::cout << yspeed << std::endl;
		//std::cout << rightKeyDown << leftKeyDown;
		//std::cout << upKeyDown << downKeyDown;
		shape.move(xspeed, yspeed);
		enemy.move(enemyXSpeed, enemyYSpeed);

		if (hit(shape.getPosition(), enemy.getPosition(), shape.getRadius(), enemy.getRadius())){
			shape.setFillColor(sf::Color::Blue);
		}
		else{
			shape.setFillColor(sf::Color::Green);
		}

		xspeed = 0;
		yspeed = 0;

		window.clear();
		window.draw(shape);
		window.draw(enemy);
		window.display();
	}

	return 0;
}