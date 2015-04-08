#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 800), "SFML works!");
	sf::CircleShape shape(10.f);

	double xspeed = 0;
	double yspeed = 0;
	double speed = 5;
	double friction = 0.01;
	double acceleration = 0.05;
	bool leftKeyDown = false;
	bool rightKeyDown = false;
	bool upKeyDown = false;
	bool downKeyDown = false;

	int maxspeed = 8;

	shape.setFillColor(sf::Color::Green);
	shape.setPosition(300, 400);
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				shape.move(-speed, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				shape.move(speed, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				shape.move(0, -speed);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				shape.move(0, speed);
			}

		}


		//std::cout << rightKeyDown << leftKeyDown;
		//std::cout << upKeyDown << downKeyDown;
		shape.move(xspeed, yspeed);


		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}