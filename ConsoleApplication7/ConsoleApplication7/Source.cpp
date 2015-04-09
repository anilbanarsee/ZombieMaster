#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cmath>
 
using sf::Vector2;
using std::cout;
using std::endl;

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

	double player2Power = 0.1;
	int WIDTH = 600;
	int HEIGHT = 600;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "ZombieMaster");
	double power = 0.1;
	double friction = 0.08;

	double topSpeed = 0.5;
	double xSpeed = 0;
	double ySpeed = 0;

	double locX;
	double locY;

	double xs = 0;
	double ys = 0;

	bool movingTowards = false;

	sf::CircleShape player(10.f);
	sf::CircleShape player2(10.f);

	player2.setPosition(WIDTH / 2, HEIGHT / 2);
	player.setPosition(300, 400);

	while (window.isOpen()){

		sf::Event event;
		Sleep(1);
		while (window.pollEvent(event)){

			

			if (event.type == sf::Event::Closed){
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right){
				sf::Vector2i c = sf::Mouse::getPosition(window);
				locX = c.x;
				locY = c.y;
				cout << "ALERT" << endl;
				movingTowards = true;
				Vector2<float> f = player2.getPosition();
				float x = f.x + player2.getRadius();
				float y = f.y + player2.getRadius();



				float diffx = locX - x;
				float diffy = locY - y;

				float t = (diffx*diffx + diffy*diffy) / player2Power;

				xs = (diffx*diffx)/t;
				if (diffx < 0){
					xs = -xs;
				}
				ys = (diffy*diffy)/t;
				if (diffy < 0){
					ys = -ys;
				}

			}
		
		}
		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

				xSpeed -= power;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

				xSpeed += power;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

				ySpeed -= power;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

				ySpeed += power;
			}
			

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
				std::cout << "ALERT" << std::endl;
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
			

			

			if (movingTowards){
				
				Vector2<float> c = player2.getPosition();
				double x2 = c.x + player2.getRadius();
				double y2 = c.y + player2.getRadius();
				if (x2 == locX || y2 == locY){
					xs = 0;
					ys = 0;
				}
				//cout << diffx << endl;
				//cout << diffy << endl;
				//cout << "ALERT" << endl;
				//movingTowards = false;

				
				
			}


			player.move(xSpeed, ySpeed);
			player2.move(xs, ys);
			//cout << movingTowards << endl;
			

			
			window.clear();
			window.draw(player2);
			window.draw(player);
			window.display();
	}
	return 0;
}