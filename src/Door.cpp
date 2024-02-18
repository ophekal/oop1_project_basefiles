
#include "StaticObjects.h"
#include "Door.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

//------------------------------------------------------------------------
Door::Door(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObjects(picture, position, size)
{

}
//-----------------------------------------------------------------------
void Door::collisionHandling()
{

}