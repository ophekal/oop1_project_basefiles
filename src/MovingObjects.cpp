
#include "GameObjects.h"
#include "MovingObjects.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

#include<iostream>

//------------------------------------------------------------------------
MovingObjects::MovingObjects(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
    :GameObjects(picture,position,size), m_position (position), m_initPosition(position)
{
    m_object.setTexture(&picture);
    m_object.setPosition(position);
}

//------------------------------------------------------------------------
bool MovingObjects::isMovementValid(const sf::RectangleShape& board,
                                    const sf::RectangleShape& newPosition)const
{
    // Get the global bounds of the board and the new position
    sf::FloatRect boardBounds = board.getGlobalBounds();
    sf::FloatRect newPositionBounds = newPosition.getGlobalBounds();

    // Check if the new position bounds are fully contained within the board bounds
    if (boardBounds.contains(newPositionBounds.left, newPositionBounds.top) &&
        boardBounds.contains(newPositionBounds.left + newPositionBounds.width, newPositionBounds.top + newPositionBounds.height))
    {
        //std::cout << "in moving objects func";

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
//------------------------------------------------------------------------
void MovingObjects::setObjectSpeed(float speed)
{
    m_objectSpeed = speed;
}
//------------------------------------------------------------------------
sf::Vector2f MovingObjects::getPosition() const
{
    return m_position;
}
//-----------------------------------------------------------------------

sf::Vector2f MovingObjects::getInitPosition()const
{
    return m_initPosition;
}
//------------------------------------------------------------------------
void MovingObjects::setDirection(const sf::Vector2f& direction)
{
    m_direction = direction;
}
//------------------------------------------------------------------------
void MovingObjects::move(sf::Time deltaTime)
{
    m_position = m_object.getPosition();
    m_object.move(m_direction * m_objectSpeed * deltaTime.asSeconds());
}
////------------------------------------------------------------------------
//void MovingObjects::setOrigin()
//{
//    m_object.setOrigin(m_object.getSize() / 2.f);
//}

//------------------------------------------------------------------------
//Function that checks the distance between two locations on board

float MovingObjects::distance(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
    return(sqrt(((v1.x - v2.x) * (v1.x - v2.x)) + ((v1.y - v2.y) * (v1.y - v2.y))));
}
//------------------------------------------------------------------------
void MovingObjects::updatePosition(const sf::Vector2f& position)
{
    m_object.setPosition(position);
    m_position = position;
}