
#include "GameObjects.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>

//------------------------------------------------------------------------
GameObjects::GameObjects (const sf::Vector2f& position, const sf::Vector2f& size)
    : m_object(size)
{
    m_object.setPosition(position);
}

//-------------------------------------------------------------------------