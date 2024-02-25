

#include "StaticObjects.h"
#include "Gift.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Mouse.h"
#include "Cat.h"

//------------------------------------------------------------------------
int Gift::m_count = 0;
//------------------------------------------------------------------------
Gift::Gift(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObjects(picture, position, size)
{
	m_count++;
}
//------------------------------------------------------------------------
int Gift::getCount()
{
	return m_count;
}
//------------------------------------------------------------------------
void Gift::collisionHandling(GameObjects& object)
{
	object.collisionHandling(*this);
}

//------------------------------------------------------------------------
void Gift::collisionHandling(Mouse& mouse)
{
	mouse.collisionHandling(*this);
}
//------------------------------------------------------------------------
void Gift::collisionHandling(Cat& cat)
{
	cat.collisionHandling(*this);
}
//------------------------------------------------------------------------
void Gift::setActive(bool activate)
{
	m_giftActive = activate;
}
//------------------------------------------------------------------------
bool Gift::isActive()const
{
	return m_giftActive;
}