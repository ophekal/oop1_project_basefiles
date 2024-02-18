#include "StaticObjects.h"
#include "Wall.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Cat.h"
#include "Mouse.h"

//------------------------------------------------------------------------
Wall::Wall(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObjects(picture, position, size)
{

}

//-------------------------------------------------------------------------
void Wall::collisionHandling(GameObjects& object)
{
	object.collisionHandling(*this);
}

//-------------------------------------------------------------------------
void Wall::collisionHandling(Mouse& mouse)
{
	mouse.collisionHandling(*this);
}

//-------------------------------------------------------------------------
void Wall::collisionHandling(Cat& cat)
{
	cat.collisionHandling(*this);
}