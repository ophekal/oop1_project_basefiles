

#include "GameObjects.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
GameObjects::GameObjects(sf::Texture& picture,const sf::Vector2f& position,const sf::Vector2f& size)
{
    m_object.setTexture(picture);

    m_object.setPosition(position);

    
}

//-------------------------------------------------------------------------