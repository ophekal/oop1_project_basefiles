
#include "StaticObjects.h"
#include "Cat.h"
#include "StupidCat.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
void StupidCat::movement(sf::Time deltaTime, const sf::RectangleShape& board)
{
	MovingObjects::setObjectSpeed(25.f);




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