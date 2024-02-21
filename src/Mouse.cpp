

#include <SFML/Graphics.hpp>
#include "Mouse.h"

//------------------------------------------------------------------------

Mouse::Mouse(const sf::Texture& icon, const sf::Vector2f& position, const sf::Vector2f& size)
	  : MovingObjects(icon, position, size)
{
	MovingObjects::setObjectSpeed(100.f);
}

//------------------------------------------------------------------------
void Mouse::movement(sf::Time deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//we need to do scale if turns left since picture is to the right
		MovingObjects::setDirection(sf::Keyboard::Left);
		checkIfMovementValid();

		m_object.move(m_direction * m_objectSpeed * deltaTime.asSeconds());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		MovingObjects::setDirection(sf::Keyboard::Right);
		m_object.move(m_direction * m_objectSpeed * deltaTime.asSeconds());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		MovingObjects::setDirection(sf::Keyboard::Up);
		m_object.move(m_direction * m_objectSpeed * deltaTime.asSeconds());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		MovingObjects::setDirection(sf::Keyboard::Down);
		m_object.move(m_direction * m_objectSpeed * deltaTime.asSeconds());
	}

}
//-----------------------------------------------------------------------
void Mouse::collisionHandling(GameObjects& object)
{
	if (&object == this)
		return;

	object.collisionHandling(*this);
}
//------------------------------------------------------------------------
void Mouse::collisionHandling(Mouse& mouse)
{

}
//------------------------------------------------------------------------
void Mouse::collisionHandling(Cat& cat)
{

}
//------------------------------------------------------------------------
void Mouse::collisionHandling(KillCatGift& gift)
{

}
//------------------------------------------------------------------------
void Mouse::collisionHandling(AddLifeGift& gift)
{

}
//-----------------------------------------------------------------------
void Mouse::collisionHandling(AddTimeGift& gift)
{

}
//----------------------------------------------------------------------
void Mouse::collisionHandling(FreezeCatGift& gift)
{

}
//---------------------------------------------------------------------
void Mouse::collisionHandling(Key& key)
{
	m_keys++;
	m_object.setPosition(m_position);
}
//---------------------------------------------------------------------
void Mouse::collisionHandling(Cheese& cheese)
{

}
//----------------------------------------------------------------------
void Mouse::collisionHandling(Door& door)
{

}