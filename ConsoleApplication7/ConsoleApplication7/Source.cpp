#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include "EntityObject.h"
#include <vector>
 
using sf::Vector2;
using std::vector;
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
float length(Vector2<float> v1){
	return sqrt((v1.x*v1.x) + (v1.y*v1.y));
}
int main()
{

	double player2Power = 0.01;
	double bulletSpeed = 0.05;

	int bulletRate = 3000;
	int bulletCounter = 0;

	int WIDTH = 600;
	int HEIGHT = 600;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "ZombieMaster");
	double power = 0.0000005;
	double friction = 0.0;

	double topSpeed = 0.5;
	double xSpeed = 0;
	double ySpeed = 0;

	float locX = 0;
	float locY = 0;

	float xs = 0;
	float ys = 0;


	float xb = 0;
	float yb = 0;


	bool movingTowards = false;

	sf::CircleShape player(10.f);
	sf::CircleShape player2(10.f);
	
	vector<sf::CircleShape*> bullets;
	vector<Vector2<float>> bulletMovement;

	player2.setPosition(WIDTH / 2, HEIGHT / 2);
	player.setPosition(300, 400);
	

	while (window.isOpen()){

		sf::Event event;
		
		while (window.pollEvent(event)){



			if (event.type == sf::Event::Closed){
				window.close();
			}
		
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right){
				sf::Vector2i c = sf::Mouse::getPosition(window);
				locX = (float) c.x;
				locY = (float) c.y;

				sf::Vector2f target(locX,locY);
				Vector2<float> current = player2.getPosition();
				current.x = current.x + player2.getRadius();
				current.y = current.y + player2.getRadius();
				Vector2<float> movement = (target - current);
				movement = movement / length(movement);
				movement.x = movement.x*player2Power;
				movement.y = movement.y*player2Power;
				xs = movement.x;
				ys = movement.y;
				movingTowards = true;
				//cout << "ALERT" << endl;
				/*movingTowards = true;
				Vector2<float> f = player2.getPosition();
				float x = f.x;
				float y = f.y;



				float diffx = locX - x;
				float diffy = locY - y;

				

				float t = (diffx*diffx + diffy*diffy) / (float) player2Power;

				cout << t << endl;
				cout << diffx << endl;
				cout << diffy << endl;

				xs = (diffx*diffx)/t;
				if (diffx < 0){
					xs = -xs;
				}
				ys = (diffy*diffy)/t;
				if (diffy < 0){
					ys = -ys;
				}

				cout << "Mouse x :" << locX;
				cout << "" << endl;
				cout << "Mouse y :" << locY;
				cout << "" << endl;

				cout << "Object x :" << x;
				cout << "" << endl;
				cout << "Object y :" << y;
				cout << "" << endl;

				cout << "Speed x :" << xs;
				cout << "" << endl;
				cout << "Speed y :" << ys;
				cout << "" << endl;*/

			}
		
		}
		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

				xSpeed -= power;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){

				xSpeed -= power;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

				xSpeed += power;

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				
				xSpeed += power;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

				ySpeed -= power;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

				ySpeed -= power;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

				ySpeed += power;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

				ySpeed += power;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&bulletCounter==0){
				sf::CircleShape  *bullet = new sf::CircleShape(2.f);
				
				Vector2<float> current = player.getPosition();
				current.x = current.x + player.getRadius();
				current.y = current.y + player.getRadius();
				(*bullet).setPosition(current);
				sf::Vector2i c = sf::Mouse::getPosition(window);
				locX = (float)c.x;
				locY = (float)c.y;

				sf::Vector2f target(locX, locY);

				Vector2<float> movement = (target - current);
				movement = movement / length(movement);
				movement.x = movement.x*bulletSpeed;
				movement.y = movement.y*bulletSpeed;
				bulletMovement.push_back(movement);
			
				bullets.push_back(bullet);
				bulletCounter = bulletRate;
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
				double r = player2.getRadius();
				
				if ((c.x+r<locX + 1 && c.x+r>locX - 1) && (c.y+r<locY + 1 && c.y+r>locY - 1)){
					movingTowards = false;
				}

				//cout << diffx << endl;
				//cout << diffy << endl;
				//cout << "ALERT" << endl;
				//movingTowards = false;

				
				
			}
			else{
				xs = 0;
				ys = 0;
			}

		
			Vector2<float> c = player.getPosition();
			
			double r = player.getRadius();

			float px = c.x + r;
			float py = c.y + r;

			if (px >= WIDTH && xSpeed > 0){
				xSpeed = 0;
			}
			if (px <= 0 && xSpeed < 0){
				xSpeed = 0;
			}

			if (py >= HEIGHT && ySpeed > 0){
				ySpeed = 0;
			}
			if (py <= 0 && ySpeed < 0){
				ySpeed = 0;
			}
			player.move(xSpeed, ySpeed);
			//player2.setPosition(locX, locY);
			player2.move(xs, ys);

			vector<sf::CircleShape*>::iterator it;
			for (it = bullets.begin(); it != bullets.end();){
				
				if (((*it)->getPosition().x > WIDTH || (*it)->getPosition().x<0) || ((*it)->getPosition().y>HEIGHT || (*it)->getPosition().y < 0)){
					delete * it;
					it = bullets.erase(it);
				}
				else{
					(*it)->move(0.05,0.05);
					++it;
				}
				//sf::CircleShape tempBullet = (*bullets.at(i));
				//if ((tempBullet.getPosition().x > WIDTH || tempBullet.getPosition().x<0) || (tempBullet.getPosition().y>HEIGHT || tempBullet.getPosition().y < 0)){
					
				//}
				//
				//cout << bulletMovement.at(i).x << endl;
				//bullets.at(i).setPosition()
			}
			if (bulletCounter > 0){
				bulletCounter--;
			}
			//cout << movingTowards << endl;
			
			//cout << bulletCounter << endl;
			//cout << bullets.size() << endl;

			window.clear();
			for (int i = 0; i < bullets.size(); i++){
				window.draw((*bullets.at(i)));
			}
			window.draw(player2);
			window.draw(player);


			EntityObject object(300, 300, "C:/Users/Hamzah/OneDrive/ZombieMaster/ConsoleApplication7/ConsoleApplication7/Data/test.png");
			window.draw(object);


			window.display();
	}
	return 0;
}