
#include "GameObjects.h"
#include "MovingObjects.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
MovingObjects::MovingObjects(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
    :GameObjects(picture,position,size), m_oldPosition (position)
{
    m_object.setTexture(&picture);
    m_object.setPosition(position);
}

//-------------------------------------------------------------------------