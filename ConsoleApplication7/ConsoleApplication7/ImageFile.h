#include <SFML/Graphics.hpp>
#include <string>
class ImageFile
{
private:
	sf::Image picture;
public:
	ImageFile();
	ImageFile(std::string imageFileName);
	sf::Image getImage(){return picture;}
};