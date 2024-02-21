
#include "GameObjects.h"
#include "MovingObjects.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

#include<iostream>

//------------------------------------------------------------------------
MovingObjects::MovingObjects(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
    :GameObjects(picture,position,size), m_position (position)
{
    m_object.setTexture(&picture);
    m_object.setPosition(position);
}

//------------------------------------------------------------------------
bool MovingObjects::isMovementValid(const sf::RectangleShape& board, const sf::RectangleShape& newPosition )const
{
    // Get the global bounds of the board and the new position
    sf::FloatRect boardBounds = board.getGlobalBounds();
    sf::FloatRect newPositionBounds = newPosition.getGlobalBounds();

    // Check if the new position bounds are fully contained within the board bounds
    if (boardBounds.contains(newPositionBounds.left, newPositionBounds.top) &&
        boardBounds.contains(newPositionBounds.left + newPositionBounds.width, newPositionBounds.top + newPositionBounds.height))
    {
        std::cout << "in moving objects func";

        // The new position is valid within the board bounds
        return true;
    }
    return false;
}
//------------------------------------------------------------------------
bool MovingObjects::positionChange()const
{
    if (m_position != m_object.getPosition())
    {
        return true;
    }
    return false;
}
//-------------------------------------------------------------------------
void MovingObjects::collisionHandling(Wall& wall)
{
  //  m_object.setPosition(m_position);
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
//----------------------------------------------------------------------
void MovingObjects::move(sf::Time deltaTime)
{
    m_position = m_object.getPosition();
    m_object.move(m_direction * m_objectSpeed * deltaTime.asSeconds());
}
