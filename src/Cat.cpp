
#include "Cat.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include "Mouse.h"
#include "GameObjects.h"
#include "Key.h"
#include "Cheese.h"
#include "Door.h"
#include "HandleResources.h"
#include "AddLifeGift.h"
#include "AddTimeGift.h"
#include "FreezeCatGift.h"
#include "KillCatGift.h"
#include <iostream>
//------------------------------------------------------------------------
int Cat::m_count = 0;
//---------------------------------------------------------------
Cat::Cat(const sf::Texture& icon, const sf::Vector2f& position, const sf::Vector2f& size)
    : MovingObjects(icon, position, size)
{
    m_count++;
}

//------------------------------------------------------------------------
int Cat::getCount()
{
    return m_count;
 }

//-----------------------------------------------------------------------
void Cat::collisionHandling(GameObjects& object)
{
	if (&object == this)
		return;

	object.collisionHandling(*this);
}
//------------------------------------------------------------------------
void Cat::collisionHandling(Wall& wall)
{
	m_object.setPosition(m_position);
}
//------------------------------------------------------------------------
void Cat::collisionHandling(Mouse& mouse)
{
	mouse.setOffBoard(true);

}
//------------------------------------------------------------------------
void Cat::collisionHandling(Cat& cat)
{
	//cat.setCovered(true);
}
//------------------------------------------------------------------------
void Cat::collisionHandling(KillCatGift& gift)
{
	//gift.setCovered(true);
}
//------------------------------------------------------------------------
void Cat::collisionHandling(AddLifeGift& gift)
{
	//gift.setCovered(true);
}
//-----------------------------------------------------------------------
void Cat::collisionHandling(AddTimeGift& gift)
{
	//gift.setCovered(true);
}
//----------------------------------------------------------------------
void Cat::collisionHandling(FreezeCatGift& gift)
{
	//gift.setCovered(true);
}
//---------------------------------------------------------------------
void Cat::collisionHandling(Key& key)
{
	//key.setCovered(true);
}
//---------------------------------------------------------------------
void Cat::collisionHandling(Cheese& cheese)
{
	//cheese.setCovered(true);
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
const sf::Time& Cat::getFreezeStartTime() const
{ 
	return m_freezeStartTime; 
}
//---------------------------------------------------------------------
void Cat::setFreezeStartTime(sf::Time time)
{
	m_freezeStartTime = time;
}
//----------------------------------------------------------------------
//void Cat::checkCatCovered(const sf::Vector2f& nextPosition,
//	                      std::vector<std::unique_ptr<StaticObjects>>& staticObjects)
//{
//	sf::Vector2f samePlace = { 0,0 };
//	if (nextPosition != samePlace)
//	{
//		std::cout << "in checkCatCovered" << std::endl;
//		for (auto index = 0; index < staticObjects.size(); index++)
//		{
//			// if the cat stand on static object
//			if (m_object.getPosition() == staticObjects[index]->getPosition())
//			{
//				std::cout << "find same position" << std::endl;
//				staticObjects[index]->setCovered(false);
//			}
//		}
//	}
//
//}