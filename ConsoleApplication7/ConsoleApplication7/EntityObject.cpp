#include <SFML/Graphics.hpp>
#include "EntityObject.h"
<<<<<<< HEAD
EntityObject::EntityObject()
{

}
=======
//This creates a new EntityObject with a position and image
>>>>>>> f87f1ada09dea1521773f7f7e650ae8b255fbd5e
EntityObject::EntityObject(float posXIn,float posYIn,std::string spriteFileName)
{
	setPosition(posXIn, posYIn);
	spriteTexture.loadFromFile(spriteFileName);
	setTexture(spriteTexture);
}