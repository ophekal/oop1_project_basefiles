#include "StaticObjects.h"
#include "Key.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

//------------------------------------------------------------------------
Key::Key(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObjects(picture, position, size)
{

}
//-------------------------------------------------------------------------
void Key::collisionHandling()
{

}