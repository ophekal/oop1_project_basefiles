
#include "StaticObjects.h"
#include "Cat.h"
#include "StupidCat.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <cstdlib>
#include <ctime>
#include "HandleResources.h"


//-------------------------------------------------------------------------------------------
void StupidCat::movement(sf::Time deltaTime, const sf::RectangleShape& board,
                         const std::unique_ptr<MovingObjects>& mouse,
                         const std::vector<std::unique_ptr<StaticObjects>>& staticObjects)
{
    MovingObjects::setObjectSpeed(25.f);
    srand(static_cast<unsigned int>(time(nullptr)));
    m_clock.restart();

    Direction direction = static_cast<Direction>(rand() % 4); // Generate a random direction

    //Calculate movement vector based on direction and speed
    sf::Vector2f movement(0.f, 0.f);
    switch (direction)
    {
        case (D_LEFT):
            m_object.setTexture(HandleResources::instance().getObjectTexture(I_L_CAT));
            movement.x -= m_objectSpeed * deltaTime.asSeconds();
            break;
        case D_RIGHT:
            m_object.setTexture(HandleResources::instance().getObjectTexture(I_R_CAT));
            movement.x += m_objectSpeed * deltaTime.asSeconds();
            break;
        case D_UP:
            movement.y -= m_objectSpeed * deltaTime.asSeconds();
            break;
        case D_DOWN:
            movement.y += m_objectSpeed * deltaTime.asSeconds();
            break;
    }
}

//-------------------------------------------------------------------------------------------
//This function updates he cat's position according to movement

void StupidCat::updateCatPosition (const sf::Vector2f &movement, const sf::RectangleShape& board)
{
    sf::RectangleShape newPosition = m_object;
    newPosition.move(movement);

    if (MovingObjects::isMovementValid(board,newPosition))
    {
        m_object.setPosition(newPosition.getPosition());
    }
    else
    {
        m_object.setPosition(m_position);
    }
}

