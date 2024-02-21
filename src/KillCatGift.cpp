#include "StaticObjects.h"
#include "Gift.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "KillCatGift.h"
#include "Mouse.h"
#include "Cat.h"
//------------------------------------------------------------------------

//------------------------------------------------------------------------
void KillCatGift::collisionHandling(GameObjects& object)
{
	object.collisionHandling(*this);
}

//------------------------------------------------------------------------
void KillCatGift::collisionHandling(Mouse& mouse)
{
	mouse.collisionHandling(*this);
}
//------------------------------------------------------------------------
void KillCatGift::collisionHandling(Cat& cat)
{
	cat.collisionHandling(*this);
}