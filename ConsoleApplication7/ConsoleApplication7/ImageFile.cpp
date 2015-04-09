#include <SFML/Graphics.hpp>
#include "ImageFile.h"
#include <string>
ImageFile::ImageFile(std::string imageFileName)
{
	picture = sf::Image();
	picture.loadFromFile(imageFileName);
}