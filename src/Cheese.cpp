
#include "StaticObjects.h"
#include "Cheese.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Cat.h"
#include "Mouse.h"

//------------------------------------------------------------------------
int Cheese::m_count = 0;
//------------------------------------------------------------------------
Cheese::Cheese (const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
  :StaticObjects(picture, position, size)
{

}
//--------------------------------------------------------------------------
Cheese::~Cheese()
{
	m_count--;
}
//--------------------------------------------------------------------------
void Cheese::collisionHandling(GameObjects& object)
{
	object.collisionHandling(*this);
}
//--------------------------------------------------------------------------
void Cheese::collisionHandling(Mouse& mouse)
{
	mouse.collisionHandling(*this);
}
//--------------------------------------------------------------------------
void Cheese::collisionHandling(Cat& cat)
{
	cat.collisionHandling(*this);
}
//-------------------------------------------------------------------------
int Cheese::getCount()
{
	return m_count;
}
