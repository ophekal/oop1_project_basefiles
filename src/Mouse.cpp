
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

//-------------------------------------------------------------------------------------------
Mouse::Mouse(const sf::Texture& icon, const sf::Vector2f& position, const sf::Vector2f& size)
	: MovingObjects(icon, position, size)
{
	MovingObjects::setObjectSpeed(100.f);
}

//-------------------------------------------------------------------------------------------
void Mouse::movement(sf::Time deltaTime, const sf::RectangleShape& board,
					const std::unique_ptr<MovingObjects>& mouse,
					const std::vector<std::unique_ptr<StaticObjects>>& staticObjects)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
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

//-------------------------------------------------------------------------------------------
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

//-------------------------------------------------------------------------------------------
void Mouse::collisionHandling(GameObjects& object)
{
	if (&object == this)
	{
		return;
	}
	object.collisionHandling(*this);
}

//-------------------------------------------------------------------------------------------
void Mouse::collisionHandling(Wall& wall)
{
	m_object.setPosition(m_position);
}

//-------------------------------------------------------------------------------------------
void Mouse::collisionHandling(Mouse& mouse)
{

}

//-------------------------------------------------------------------------------------------
void Mouse::collisionHandling(Cat& cat)
{
	HandleResources::instance().playSound(G_MOUSE);
	m_lives--;
	setOffBoard(true);  
}

//-------------------------------------------------------------------------------------------
void Mouse::collisionHandling(KillCatGift& gift)
{
	HandleResources::instance().playSound(G_GIFT);
	m_score += 5;
	gift.setOffBoard(true);
	gift.setActive(true);
}

//-------------------------------------------------------------------------------------------
void Mouse::collisionHandling(AddLifeGift& gift)
{
	HandleResources::instance().playSound(G_GIFT);
	m_score += 5;
	gift.setOffBoard(true);
	gift.setActive(true);
}

//-------------------------------------------------------------------------------------------
void Mouse::collisionHandling(AddTimeGift& gift)
{
	HandleResources::instance().playSound(G_GIFT);
	m_score += 5;
	gift.setOffBoard(true);
	gift.setActive(true);
}

//-------------------------------------------------------------------------------------------
void Mouse::collisionHandling(FreezeCatGift& gift)
{
	HandleResources::instance().playSound(G_GIFT);
	m_score += 5;
	gift.setOffBoard(true);
	gift.setActive(true);
}

//-------------------------------------------------------------------------------------------
void Mouse::collisionHandling(Key& key)
{
	HandleResources::instance().playSound(G_KEY);
	m_keys++;
	key.setOffBoard(true); 
}

//-------------------------------------------------------------------------------------------
void Mouse::collisionHandling(Cheese& cheese)
{
	HandleResources::instance().playSound(G_CHEESE);
	m_score += 10;
	cheese.setOffBoard(true);
}

//-------------------------------------------------------------------------------------------
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

//-------------------------------------------------------------------------------------------
int Mouse::getKeys()const
{
	return m_keys;
}

//-------------------------------------------------------------------------------------------
int Mouse::getLives()const
{
	return m_lives;
}

//-------------------------------------------------------------------------------------------
void Mouse::setLives(int setLive)
{
	m_lives= setLive;
}

//-------------------------------------------------------------------------------------------
int Mouse::getScore()const
{
	return m_score;
}

//-------------------------------------------------------------------------------------------
void Mouse::setScore(int score)
{
	m_score = score;
}