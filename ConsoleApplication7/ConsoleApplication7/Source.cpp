#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include "Projectile.h"
#include <vector>
#include <cstdlib>
#include "PlayerObject.h"

using sf::Vector2;
using sf::Vector2f;
using std::vector;
using std::cout;
using std::endl;

#define PI 3.14159265

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}
bool hit(Vector2f v1, Vector2f v2, double r1, double r2){



	double comR = r1 + r2;


	double xpos1 = v1.x;
	double xpos2 = v2.x;

	double ypos1 = v1.y;
	double ypos2 = v2.y;

	double diffX = xpos1 - xpos2;
	double diffY = ypos1 - ypos2;

	atan(1);
	diffX = diffX*diffX;
	diffY = diffY*diffY;

	double distance = sqrt(diffX + diffY);

	if (comR >= distance){
		return true;
	}
	return false;
}
bool hit(Vector2f v1, Vector2f v2, double r1){


	double comR = r1;


	double xpos1 = v1.x;
	double xpos2 = v2.x;

	double ypos1 = v1.y;
	double ypos2 = v2.y;

	double diffX = xpos1 - xpos2;
	double diffY = ypos1 - ypos2;

	atan(1);
	diffX = diffX*diffX;
	diffY = diffY*diffY;

	double distance = sqrt(diffX + diffY);

	if (comR >= distance){
		return true;
	}
	
	return false;
}
float length(Vector2f v1){
	return sqrt((v1.x*v1.x) + (v1.y*v1.y));
}
int main()
{

	double player2Power = 0.3;
	double bulletSpeed = 0.75;

	int numberOfBullets = 1;
	int bulletRate = 100;
	int bulletCounter = 0;

	int WIDTH = 1000;
	int HEIGHT = 1000;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "ZombieMaster");
	double power = 0.005;
	double friction = 0.0025;

	double topSpeed = 0.5;
	double xSpeed = 0;
	double ySpeed = 0;
	
	float locX = 0;
	float locY = 0;

	float locX2 = 0;
	float locY2 = 0;

	float xs = 0;
	float ys = 0;
	float xs2 = 0;
	float ys2 = 0;
	double spreadAmount = 0;
	
	float xb = 0;
	float yb = 0;
	bool gravity = false;
	bool antigravity = true;
	int spreadCounter = 0;
	int spreadCounterMax = 1;

	bool aiShooting = false;

	bool movingTowards = false;
	bool movingTowards2 = false;

	//Testing playerObject code
	PlayerObject playerobject(300,200,"Data/test.png");
	


	sf::CircleShape player(10.f);
	sf::CircleShape player2(10.f);
	sf::CircleShape player3(10.f);
	player.setOrigin(player.getRadius(), player.getRadius());
	player2.setOrigin(player2.getRadius(), player2.getRadius());
	player3.setOrigin(player3.getRadius(), player3.getRadius());
	Vector2f move;
	move.x = 0;
	move.y = 0;
	Projectile object(300, 300, "test.png", move);

	vector<Projectile*> bullets;
	vector<Vector2f> bulletMovement;

	player3.setPosition(WIDTH / 2, HEIGHT / 3);
	player2.setPosition(WIDTH / 2, HEIGHT / 2);
	player.setPosition(300, 400);


	while (window.isOpen()){
		Sleep(1);
		sf::Event event;

		while (window.pollEvent(event)){



			if (event.type == sf::Event::Closed){
				window.close();
			}
			
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))){
				sf::Vector2i c = sf::Mouse::getPosition(window);
				locX = (float)c.x;
				locY = (float)c.y;

				sf::Vector2f target(locX, locY);
				Vector2f current = player2.getPosition();

				Vector2f movement = (target - current);
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
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
				sf::Vector2i c = sf::Mouse::getPosition(window);
				locX2 = (float)c.x;
				locY2 = (float)c.y;

				sf::Vector2f target(c.x, c.y);
				Vector2f current = player3.getPosition();

				Vector2f movement = (target - current);
				movement = movement / length(movement);
				movement.x = movement.x*player2Power;
				movement.y = movement.y*player2Power;
				xs2 = movement.x;
				ys2 = movement.y;
				movingTowards2 = true;
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
			aiShooting = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)){
			aiShooting = false;
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)&&spreadCounter==0){

			if (spreadAmount >= 0){
				spreadAmount-=0.1;
			}
			spreadCounter = spreadCounterMax;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)&&spreadCounter==0){

			if (spreadAmount <= 360){
				spreadAmount+=0.1;
			}
			spreadCounter = spreadCounterMax;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && bulletCounter == 0){
			
			for (int i = 0; i < numberOfBullets; i++){
				Vector2f current = player.getPosition();
				
				double spread = 0;
				if (spreadAmount > 0){
					spread = fRand(-spreadAmount / 2, spreadAmount / 2);
				}
				
				//cout << spread << endl;

				sf::Vector2i c = sf::Mouse::getPosition(window);


				sf::Vector2f target(c.x, c.y);

				Vector2f movement = (target - current);
				movement = movement / length(movement);
				movement.x = movement.x*bulletSpeed;
				movement.y = movement.y*bulletSpeed;

				double angle = (atan(movement.y / movement.x) * 180 / PI) + 90;
				if (movement.x < 0){
					angle += 180;
				}

				angle += spread;
				//cout << spread << endl;
				double radians = angle*(PI / 180);
				double hyp = sqrt(movement.y*movement.y + movement.x*movement.x);

				movement.x = sin(radians)*hyp;
				movement.y = -(cos(radians)*hyp);

				//cout << sin(radians) * distance << "," << cos(radians)*distance << endl;

				Projectile  *bullet = new Projectile(current.x, current.y, "test.png", movement);

				bullets.push_back(bullet);
				bulletCounter = bulletRate;
			}
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

			Vector2f c = player2.getPosition();


			if ((c.x<locX + 1 && c.x>locX - 1) && (c.y<locY + 1 && c.y>locY - 1)){
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
		if (movingTowards2){

			Vector2f c = player3.getPosition();


			if ((c.x<locX2 + 1 && c.x>locX2 - 1) && (c.y<locY2 + 1 && c.y>locY2 - 1)){
				movingTowards2 = false;
			}

			//cout << diffx << endl;
			//cout << diffy << endl;
			//cout << "ALERT" << endl;
			//movingTowards = false;



		}
		else{
			xs2 = 0;
			ys2 = 0;
		}

		Vector2f c = player.getPosition();

		

		float px = c.x;
		float py = c.y;

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
		player3.move(xs2, ys2);
		bool gotHit = false;
		vector<Projectile*>::iterator it;
		for (it = bullets.begin(); it != bullets.end();){
			if (gravity){
				Vector2f current = (*it)->getPosition();

			

				sf::Vector2f target = player2.getPosition();


				

				Vector2f movement = (target - current);
				
				double length = sqrt((movement.x*movement.x) + (movement.y*movement.y));
				//cout << length << endl;
				
				movement.x = ((movement.x/length)*(1/length))/1000;
				movement.y = ((movement.y/length)*(1/length))/1000;

				
				//cout << movement.x << " , " << movement.y << endl;
				(*it)->setMovement(((*it)->getMovement()) + movement);
			}
			else if (antigravity){
				Vector2f current = (*it)->getPosition();



				sf::Vector2f target = player2.getPosition();




				Vector2f movement = (target - current);

				double length = sqrt((movement.x*movement.x) + (movement.y*movement.y));
				//cout << length << endl;

				movement.x = ((movement.x / length)*(1 / length)) / 9.5;
				movement.y = ((movement.y / length)*(1 / length)) / 9.5;


				//cout << movement.x << " , " << movement.y << endl;
				(*it)->setMovement(((*it)->getMovement()) - movement);
			}
			if (hit(player2.getPosition(), (*it)->getPosition(), player2.getRadius())){
				delete * it;
				it = bullets.erase(it);
				gotHit = true;
			}
			else if (((*it)->getPosition().x > WIDTH || (*it)->getPosition().x<0) || ((*it)->getPosition().y>HEIGHT || (*it)->getPosition().y < 0)){
				delete * it;
				it = bullets.erase(it);
			}
			else{
				(*it)->incr();
				++it;
			}
			
			//sf::CircleShape tempBullet = (*bullets.at(i));
			//if ((tempBullet.getPosition().x > WIDTH || tempBullet.getPosition().x<0) || (tempBullet.getPosition().y>HEIGHT || tempBullet.getPosition().y < 0)){

			//}
			//
			//cout << bulletMovement.at(i).x << endl;
			//bullets.at(i).setPosition()
		}
		if (gotHit){
			player2.setFillColor(sf::Color::Red);
		}
		else{
			player2.setFillColor(sf::Color::Green);
		}
		if (bulletCounter > 0){
			bulletCounter--;
		}
		if (spreadCounter > 0){
			spreadCounter--;
		}

		if (aiShooting && bulletCounter==0){
			
			for (int i = 0; i < numberOfBullets; i++){
				
				Vector2f current = player3.getPosition();

				double spread = 0;
				if (spreadAmount > 0){
					spread = fRand(-spreadAmount / 2, spreadAmount / 2);
				}

				//cout << spread << endl;

				sf::Vector2f c = player.getPosition();


				sf::Vector2f target(c.x, c.y);

				Vector2f movement = (target - current);
				movement = movement / length(movement);
				movement.x = movement.x*bulletSpeed;
				movement.y = movement.y*bulletSpeed;

				double angle = (atan(movement.y / movement.x) * 180 / PI) + 90;
				if (movement.x < 0){
					angle += 180;
				}

				angle += spread;
				//cout << spread << endl;
				double radians = angle*(PI / 180);
				double hyp = sqrt(movement.y*movement.y + movement.x*movement.x);

				movement.x = sin(radians)*hyp;
				movement.y = -(cos(radians)*hyp);

				//cout << sin(radians) * distance << "," << cos(radians)*distance << endl;

				Projectile  *bullet = new Projectile(current.x, current.y, "test.png", movement);

				bullets.push_back(bullet);
				bulletCounter = bulletRate;
			}
		}
		
		//cout << spreadAmount << endl;
		//cout << movingTowards << endl;

		//cout << bulletCounter << endl;
		//cout << bullets.size() << endl;


		window.clear();
		window.draw(player2);
		for (int i = 0; i < bullets.size(); i++){
			window.draw((*bullets.at(i)));
		}
		window.draw(player3);
		
		window.draw(player);


		
		window.draw(object);

		// Get movement for player then draw it
		playerobject.getMovement();
		window.draw(playerobject);



		window.display();
	}
	return 0;
}