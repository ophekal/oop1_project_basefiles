

#include <SFML/Graphics.hpp>
#include "Mouse.h"
#include <iostream>
#include "GameObjects.h"
#include "Key.h"
#include "Cheese.h"
#include "Door.h"
#include "HandleResources.h"
#include "Macros.h"
#include "AddLifeGift.h"
#include "AddTimeGift.h"
#include "FreezeCatGift.h"
#include "KillCatGift.h"
//------------------------------------------------------------------------

Mouse::Mouse(const sf::Texture& icon, const sf::Vector2f& position, const sf::Vector2f& size)
	: MovingObjects(icon, position, size)
{
	MovingObjects::setObjectSpeed(100.f);
}

//------------------------------------------------------------------------
void Mouse::movement(sf::Time deltaTime, const sf::RectangleShape& board,
					const std::unique_ptr<MovingObjects>& mouse,
					const std::vector<std::unique_ptr<StaticObjects>>& staticObjects)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//we need to do scale if turns left since picture is to the right
		setDirection(Directions[D_LEFT]);
		m_object.setTexture(HandleResources::instance().getObjectTexture(I_L_MOUSE));
		checkMovement(deltaTime, board);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setDirection(Directions[D_RIGHT]);
		m_object.setTexture(HandleResources::instance().getObjectTexture(I_R_MOUSE));
		checkMovement(deltaTime, board);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setDirection(Directions[D_UP]);
		//m_object.setTexture(HandleResources::instance().getBackgroundTexture(I_MOUSEUP));
		checkMovement(deltaTime, board);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setDirection(Directions[D_DOWN]);
		//m_object.setTexture(HandleResources::instance().getBackgroundTexture(I_MOUSEDOWN));
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
	m_lives--;
	setOffBoard(true);  
}
//------------------------------------------------------------------------
void Mouse::collisionHandling(KillCatGift& gift)
{
	m_score += 5;
	gift.setOffBoard(true);
	gift.setActive(true);
}
//------------------------------------------------------------------------
void Mouse::collisionHandling(AddLifeGift& gift)
{
	m_score += 5;
	gift.setOffBoard(true);
	gift.setActive(true);
}
//-----------------------------------------------------------------------
void Mouse::collisionHandling(AddTimeGift& gift)
{
	m_score += 5;
	gift.setOffBoard(true);
	gift.setActive(true);
}
//----------------------------------------------------------------------
void Mouse::collisionHandling(FreezeCatGift& gift)
{
	m_score += 5;
	gift.setOffBoard(true);
	gift.setActive(true);
}
//---------------------------------------------------------------------
void Mouse::collisionHandling(Key& key)
{
	m_keys++;
	key.setOffBoard(true);  // m_offBoard = true;
	//std::cout << "num of keys:" << m_keys << std::endl;
}
//---------------------------------------------------------------------
void Mouse::collisionHandling(Cheese& cheese)
{
	m_score += 10;
	cheese.setOffBoard(true);
}
//----------------------------------------------------------------------
void Mouse::collisionHandling(Door& door)
{
	if (m_keys > 0)
	{
		m_keys--;
		m_score += 2;
		door.setOffBoard(true);
	}
	else
	{
		m_object.setPosition(m_position);
	}

}
//----------------------------------------------------------------------
int Mouse::getKeys()const
{
	return m_keys;
}

//---------------------------------------------------------------------
int Mouse::getLives()const
{
	return m_lives;
}
//---------------------------------------------------------------------
void Mouse::setLives(int setLive)
{
	m_lives= setLive;
}
//---------------------------------------------------------------------
int Mouse::getScore()const
{
	return m_score;
}
//---------------------------------------------------------------------
void Mouse::setScore(int score)
{
	m_score = score;
}