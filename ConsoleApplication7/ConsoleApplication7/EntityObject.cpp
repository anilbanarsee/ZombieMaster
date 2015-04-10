#include <SFML/Graphics.hpp>
#include "EntityObject.h"
#include "ImageFile.h"
EntityObject::EntityObject(float posXIn,float posYIn,std::string spriteFileName)
{
	setPosition(posXIn, posYIn);
	spriteTexture.loadFromFile(spriteFileName);
}