

#include <SFML/Graphics.hpp>
#include "Mouse.h"
#include <iostream>
//------------------------------------------------------------------------

Mouse::Mouse(const sf::Texture& icon, const sf::Vector2f& position, const sf::Vector2f& size)
	  : MovingObjects(icon, position, size)
{
	MovingObjects::setObjectSpeed(100.f);
}

//------------------------------------------------------------------------
void Mouse::movement(sf::Time deltaTime, const sf::RectangleShape& board)
{
	m_direction = {0, 0};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//we need to do scale if turns left since picture is to the right
		MovingObjects::setDirection(sf::Keyboard::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		MovingObjects::setDirection(sf::Keyboard::Right);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		MovingObjects::setDirection(sf::Keyboard::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		MovingObjects::setDirection(sf::Keyboard::Down);
	}

	sf::RectangleShape newPosition = m_object;
	newPosition.move(m_direction * m_objectSpeed * deltaTime.asSeconds());

	if (MovingObjects::isMovementValid(board,newPosition))
	{
		if(checkCollision())
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