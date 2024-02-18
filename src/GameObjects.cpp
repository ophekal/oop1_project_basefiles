

#include "GameObjects.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
GameObjects::GameObjects(const sf::Vector2f& position, const sf::Vector2f& size)
    : m_object(size)
{
    m_object.setTexture(picture);

    m_object.setPosition(position);

    
}

//-------------------------------------------------------------------------