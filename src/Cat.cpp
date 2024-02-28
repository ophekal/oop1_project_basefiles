
#include "Cat.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include "Mouse.h"
#include "GameObjects.h"
#include "Key.h"
#include "Cheese.h"
#include "Door.h"
#include "Wall.h"
#include "HandleResources.h"
#include "AddLifeGift.h"
#include "AddTimeGift.h"
#include "FreezeCatGift.h"
#include "KillCatGift.h"


//---------------------------------------------------------------------------------------
int Cat::m_count = 0;

//---------------------------------------------------------------------------------------
Cat::Cat(const sf::Texture& icon, const sf::Vector2f& position, const sf::Vector2f& size)
    : MovingObjects(icon, position, size)
{
    m_count++;
}

//---------------------------------------------------------------------------------------
int Cat::getCount()
{
    return m_count;
}

//---------------------------------------------------------------------------------------
void Cat::collisionHandling(GameObjects& object)
{
	if (&object == this)
	{
		return;
	}

	object.collisionHandling(*this);
}

//---------------------------------------------------------------------------------------
void Cat::collisionHandling(Wall& wall)
{
	m_object.setPosition(m_position);
}

//---------------------------------------------------------------------------------------
void Cat::collisionHandling(Mouse& mouse)
{
	mouse.setOffBoard(true);
}

//----------------------------------------------------------------------
void Cat::collisionHandling(Door& door)
{
	m_object.setPosition(m_position);
}

//----------------------------------------------------------------------
void Cat::setCatFreeze(bool freeze)
{
	m_catFreeze = freeze;
}

//----------------------------------------------------------------------
bool Cat::isFreeze()const
{
	return m_catFreeze;
}

//---------------------------------------------------------------------
const sf::Time& Cat::getFreezeTime() const
{ 
	return (m_clock.getElapsedTime() - m_freezeStartTime);
}

//---------------------------------------------------------------------
void Cat::setFreezeStartTime()
{
	m_freezeStartTime = m_clock.getElapsedTime();
}
