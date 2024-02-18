
#include "Cat.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>

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
void Cat::collisionHandling(Mouse& mouse)
{

}
//------------------------------------------------------------------------
void Cat::collisionHandling(Cat& cat)
{

}
//------------------------------------------------------------------------
void Cat::collisionHandling(KillCatGift& gift)
{

}
//------------------------------------------------------------------------
void Cat::collisionHandling(AddLifeGift& gift)
{

}
//-----------------------------------------------------------------------
void Cat::collisionHandling(AddTimeGift& gift)
{

}
//----------------------------------------------------------------------
void Cat::collisionHandling(FreezeCatGift& gift)
{

}
//---------------------------------------------------------------------
void Cat::collisionHandling(Key& key)
{

}
//---------------------------------------------------------------------
void Cat::collisionHandling(Cheese& cheese)
{
	
}
//----------------------------------------------------------------------
void Cat::collisionHandling(Door& door)
{
	
}