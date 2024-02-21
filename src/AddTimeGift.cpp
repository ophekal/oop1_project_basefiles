#include "StaticObjects.h"
#include "Gift.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "AddTimeGift.h"
#include "Mouse.h"
#include "Cat.h"


//-------------------------------------------------------------------------
void AddTimeGift::collisionHandling(GameObjects& object)
{
	object.collisionHandling(*this);
}

//-------------------------------------------------------------------------
void AddTimeGift::collisionHandling(Mouse& mouse)
{
	mouse.collisionHandling(*this);
}

//-------------------------------------------------------------------------
void AddTimeGift::collisionHandling(Cat& cat)
{
	cat.collisionHandling(*this);
}