
#include "GameObjects.h"
#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
StaticObjects::StaticObjects(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
              :GameObjects(picture, position, size)
{
   // m_currOnBoard = true;
}