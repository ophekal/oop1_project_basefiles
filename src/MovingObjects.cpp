
#include "GameObjects.h"
#include "MovingObjects.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
MovingObjects::MovingObjects(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
    :GameObjects(picture,position,size), m_position (position)
{
    m_object.setTexture(&picture);
    m_object.setPosition(position);
}

//------------------------------------------------------------------------
bool MovingObjects:: isMovementValid ()
{

    
}

//-------------------------------------------------------------------------
void MovingObjects::collisionHandling(Wall& wall)
{
    m_object.setPosition(m_position);
}
//------------------------------------------------------------------------
void MovingObjects::setObjectSpeed(float speed)
{
    m_objectSpeed = speed;
}
//-------------------------------------------------------------------------
void MovingObjects::setDirection(sf::Keyboard::Key key)
{
    switch (key)
    {
        case sf::Keyboard::Key::Left:
            m_direction = sf::Vector2f(-1, 0);
            break;

        case sf::Keyboard::Key::Right:
            m_direction = sf::Vector2f(1, 0);
            break;

        case sf::Keyboard::Key::Up:
            m_direction = sf::Vector2f(0, -1);
            break;

        case sf::Keyboard::Key::Down:
            m_direction = sf::Vector2f(0, 1);
            break;

        default:
            m_direction = sf::Vector2f(0, 0);
            break;
    }
}