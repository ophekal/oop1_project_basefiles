

#include "StaticObjects.h"
#include "Gift.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

//------------------------------------------------------------------------
int Gift::m_count = 0;
//------------------------------------------------------------------------
Gift::Gift(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObjects(picture, position, size)
{

}
//------------------------------------------------------------------------
int Gift::getCount()
{
	return m_count;
}
//------------------------------------------------------------------------
void Gift::collisionHandling(GameObjects&)
{

}
//------------------------------------------------------------------------
void Gift::collisionHandling(Cat&)
{

}
//------------------------------------------------------------------------
void Gift::collisionHandling(Mouse&)
{

}