#include "StaticObjects.h"
#include "Cat.h"
#include "SmartCat.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
void SmartCat::movement(sf::Time deltaTime)
{
	MovingObjects::setObjectSpeed(40.f);

}