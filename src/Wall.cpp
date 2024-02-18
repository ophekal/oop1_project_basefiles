#include "StaticObjects.h"
#include "Wall.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

//------------------------------------------------------------------------
Wall::Wall(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObjects(picture, position, size)
{

}
//------------------------------------------------------------------------
void Wall::collisionHandling()
{

}