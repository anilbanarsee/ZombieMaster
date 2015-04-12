#include <SFML/Graphics.hpp>
#include "EntityObject.h"
EntityObject::EntityObject()
{

}
EntityObject::EntityObject(float posXIn,float posYIn,std::string spriteFileName)
{
	setPosition(posXIn, posYIn);
	spriteTexture.loadFromFile(spriteFileName);
	setTexture(spriteTexture);
}