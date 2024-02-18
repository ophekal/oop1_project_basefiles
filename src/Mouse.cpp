

#include <SFML/Graphics.hpp>
#include "Mouse.h"


//------------------------------------------------------------------------

Mouse::Mouse(const sf::Texture& icon, const sf::Vector2f& position, const sf::Vector2f& size)
	  : MovingObjects(icon, position, size)
{

}