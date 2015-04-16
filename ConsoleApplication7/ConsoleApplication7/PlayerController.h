//This is the PlayerController class
//Its a class which moves a EntityObject (soon to be player object) around the screen using the wasd keys
class PlayerController
{
private:
	double speed;
	double xSpeed = 0;
	double ySpeed = 0;
	double topSpeed = 0.5;
	double friction = 0.0025;
public:
	PlayerController();
	PlayerController(double speedAmount);
	void getMovement();
	double getXSpeed();
	double getYSpeed();
};