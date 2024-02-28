
#include "StaticObjects.h"
#include "Gift.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "FreezeCatGift.h"
#include "Mouse.h"
#include "Cat.h"
#include "Controller.h"

//-------------------------------------------------------------------------
void FreezeCatGift::collisionHandling(GameObjects& object)
{
	object.collisionHandling(*this);
}

//-------------------------------------------------------------------------
void FreezeCatGift::collisionHandling(Mouse& mouse)
{
	mouse.collisionHandling(*this);
}

//-------------------------------------------------------------------------
void FreezeCatGift::collisionHandling(Cat& cat)
{
	cat.collisionHandling(*this);
}
//------------------------------------------------------------------------
void FreezeCatGift::handleGift(Controller& controller)
{
	controller.freezeCat();
}