//This is the PlayerController class
//Its a class which moves a EntityObject (soon to be player object) around the screen using the wasd keys
class PlayerController
{
private:
	float speed;
	float xSpeed = 0;
	float ySpeed = 0;
	float topSpeed = 0.5f;
	float friction = 0.0025f;
public:
	PlayerController();
	PlayerController(float speedAmount);
	void getMovement();
	double getXSpeed();
	double getYSpeed();
};