
#include "StaticObjects.h"
#include "Cat.h"
#include "StupidCat.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <cstdlib> // For rand() function
#include <ctime>   // For seeding rand()
#include "HandleResources.h"
//------------------------------------------------------------------------
void StupidCat::movement(sf::Time deltaTime, const sf::RectangleShape& board,
                         const std::unique_ptr<MovingObjects>& mouse,
                         const std::vector<std::unique_ptr<StaticObjects>>& staticObjects)
{
	MovingObjects::setObjectSpeed(25.f);
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Define possible directions

   Direction direction = static_cast<Direction>(rand() % 4); // Generate a random direction

    // Calculate movement vector based on direction and speed
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

    // Update cat's position while avoiding collisions with walls
    sf::RectangleShape newPosition = m_object;
    newPosition.move(movement);

    if (MovingObjects::isMovementValid(board, newPosition))
    {
        //std::cout << "movement is valid";
        //checkCatCovered(newPosition.getPosition(), staticObjects);
        m_object.setPosition(newPosition.getPosition());
    }
    else
    {
        m_object.setPosition(m_position);
    }


    //sf::FloatRect catBounds = m_object.getGlobalBounds();
    //sf::FloatRect boardBounds = board.getGlobalBounds();

    //// Check for collision with the board's boundaries
    //if (boardBounds.contains(catBounds.left + movement.x, catBounds.top) &&
    //    boardBounds.contains(catBounds.left + catBounds.width + movement.x, catBounds.top) &&
    //    boardBounds.contains(catBounds.left + movement.x, catBounds.top + catBounds.height) &&
    //    boardBounds.contains(catBounds.left + catBounds.width + movement.x, catBounds.top + catBounds.height))
    //{
    //    // No collision with board, update position
    //    m_object.move(movement);
    //}



}
//------------------------------------------------------------------------

/*
* #include <cstdlib> // For rand() function
#include <ctime>   // For seeding rand()

void StupidCat::movement(sf::Time deltaTime, const sf::RectangleShape& board)
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Define possible directions
    enum Direction { Up, Down, Left, Right };
    Direction direction = static_cast<Direction>(rand() % 4); // Generate a random direction

    // Calculate movement vector based on direction and speed
    sf::Vector2f movement(0.f, 0.f);
    switch (direction)
    {
    case Up:
        movement.y -= getObjectSpeed() * deltaTime.asSeconds();
        break;
    case Down:
        movement.y += getObjectSpeed() * deltaTime.asSeconds();
        break;
    case Left:
        movement.x -= getObjectSpeed() * deltaTime.asSeconds();
        break;
    case Right:
        movement.x += getObjectSpeed() * deltaTime.asSeconds();
        break;
    }

    // Update cat's position while avoiding collisions with walls
    sf::FloatRect catBounds = m_object.getGlobalBounds();
    sf::FloatRect boardBounds = board.getGlobalBounds();

    // Check for collision with the board's boundaries
    if (boardBounds.contains(catBounds.left + movement.x, catBounds.top) &&
        boardBounds.contains(catBounds.left + catBounds.width + movement.x, catBounds.top) &&
        boardBounds.contains(catBounds.left + movement.x, catBounds.top + catBounds.height) &&
        boardBounds.contains(catBounds.left + catBounds.width + movement.x, catBounds.top + catBounds.height))
    {
        // No collision with board, update position
        m_object.move(movement);
    }
}

*/