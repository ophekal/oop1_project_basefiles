

#include <SFML/Graphics.hpp>
#include "Mouse.h"
#include <iostream>
#include "GameObjects.h"
//------------------------------------------------------------------------

Mouse::Mouse(const sf::Texture& icon, const sf::Vector2f& position, const sf::Vector2f& size)
	  : MovingObjects(icon, position, size)
{
	MovingObjects::setObjectSpeed(100.f);
}

//------------------------------------------------------------------------
void Mouse::movement(sf::Time deltaTime, const sf::RectangleShape& board)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//we need to do scale if turns left since picture is to the right
		setDirection(Directions[D_LEFT]);
		checkMovement(deltaTime, board);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setDirection(Directions[D_RIGHT]);
		checkMovement(deltaTime, board);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setDirection(Directions[D_UP]);
		checkMovement(deltaTime, board);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setDirection(Directions[D_DOWN]);
		checkMovement(deltaTime, board);
		return;
	}
	else
	{
		m_direction = { 0,0 };
	}

}
//-----------------------------------------------------------------------
void Mouse::checkMovement(sf::Time deltaTime, const sf::RectangleShape& board)
{
	sf::RectangleShape newPosition= m_object;
	newPosition.move(m_direction * m_objectSpeed * deltaTime.asSeconds());

	if (MovingObjects::isMovementValid(board, newPosition))
	{
		std::cout << "movement is valid";

		m_object.setPosition(newPosition.getPosition());
	}
	else
	{
		m_object.setPosition(m_position);
	}

}

//-----------------------------------------------------------------------
void Mouse::collisionHandling(GameObjects& object)
{
	if (&object == this)
	{
		return;
	}
	object.collisionHandling(*this);
}
//-----------------------------------------------------------------------
void Mouse::collisionHandling(Wall& wall)
{
	m_object.setPosition(m_position);
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
	m_position = m_object.getPosition();
	//m_object.setPosition(m_position);
}
//---------------------------------------------------------------------
void Mouse::collisionHandling(Cheese& cheese)
{

}
//----------------------------------------------------------------------
void Mouse::collisionHandling(Door& door)
{

}