#include "StaticObjects.h"
#include "Gift.h"
#include "Macros.h"
#include "AddLifeGift.h"
#include "Mouse.h"
#include "Cat.h"
#include "Controller.h"
#include <SFML/Graphics.hpp>

//-------------------------------------------------------------------------
void AddLifeGift::collisionHandling(GameObjects& object)
{
	object.collisionHandling(*this);
}

//-------------------------------------------------------------------------
void AddLifeGift::collisionHandling(Mouse& mouse)
{
	mouse.collisionHandling(*this);
}

//-------------------------------------------------------------------------
void AddLifeGift::collisionHandling(Cat& cat)
{
	cat.collisionHandling(*this);
}
//-------------------------------------------------------------------------
void AddLifeGift::handleGift(Controller& controller)
{
	controller.incLife();
}