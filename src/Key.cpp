#include "GameObjects.h"
#include "StaticObjects.h"
#include "Key.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Mouse.h"
#include "Cat.h"

//------------------------------------------------------------------------
Key::Key(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObjects(picture, position, size)
{

}
//-------------------------------------------------------------------------
void Key::collisionHandling(GameObjects& object)
{
	object.collisionHandling(*this);
}

//-------------------------------------------------------------------------
void Key::collisionHandling(Mouse& mouse)
{
	mouse.collisionHandling(*this);
}

//-------------------------------------------------------------------------
void Key::collisionHandling(Cat& cat)
{
	cat.collisionHandling(*this);
}
