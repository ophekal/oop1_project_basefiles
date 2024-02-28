#include "StaticObjects.h"
#include "Gift.h"
#include "Macros.h"
#include "AddTimeGift.h"
#include "Mouse.h"
#include "Cat.h"
#include "Controller.h"
#include <SFML/Graphics.hpp>

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
//------------------------------------------------------------------------
void AddTimeGift::handleGift(Controller& controller)
{
	controller.incTime();

}