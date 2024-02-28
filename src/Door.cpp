
#include "StaticObjects.h"
#include "Door.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Mouse.h"
#include"Cat.h"

//----------------------------------------------------------------------------------------
Door::Door(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObjects(picture, position, size) {}

//----------------------------------------------------------------------------------------
void Door::collisionHandling(GameObjects& object)
{
	object.collisionHandling(*this);
}

//----------------------------------------------------------------------------------------
void Door::collisionHandling(Mouse& mouse)
{
	mouse.collisionHandling(*this);
}

//----------------------------------------------------------------------------------------
void Door::collisionHandling(Cat& cat)
{
	cat.collisionHandling(*this);
}