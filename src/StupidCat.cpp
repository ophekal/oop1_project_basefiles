
#include "StaticObjects.h"
#include "Cat.h"
#include "StupidCat.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
void StupidCat::movement(sf::Time deltaTime, const sf::RectangleShape& board)
{
	MovingObjects::setObjectSpeed(25.f);
}
//------------------------------------------------------------------------

