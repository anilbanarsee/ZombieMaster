#include <SFML/Graphics.hpp>
#include "ImageFile.h"
/*This is a EntityObject, the base class from which all other objects are derived
  It needs a position,image and collision data*/
class EntityObject
{
private:
	int posX;
	int posY;
public:
	EntityObject(){};
	int getPosX(){ return posX; };
	int getPosY(){ return posY; };
};