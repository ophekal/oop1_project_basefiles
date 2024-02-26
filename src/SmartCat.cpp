#include "StaticObjects.h"
#include "Cat.h"
#include "SmartCat.h"
#include "GameObjects.h"
#include "Wall.h"
#include "Door.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <iostream>
#include "HandleResources.h"
//------------------------------------------------------------------------
void SmartCat::movement(sf::Time deltaTime, const sf::RectangleShape& board,
                        const std::unique_ptr<MovingObjects>& mouse,
                        const std::vector<std::unique_ptr<StaticObjects>>& staticObjects)
{
   MovingObjects::setObjectSpeed(40.f);

   sf::RectangleShape up = m_object;
   sf::RectangleShape down = m_object;
   sf::RectangleShape left = m_object;
   sf::RectangleShape right = m_object;

   up.move(Directions[D_UP] * m_objectSpeed * deltaTime.asSeconds());
   down.move(Directions[D_DOWN] * m_objectSpeed * deltaTime.asSeconds());
   left.move(Directions[D_LEFT] * m_objectSpeed * deltaTime.asSeconds());
   right.move(Directions[D_RIGHT] * m_objectSpeed * deltaTime.asSeconds());
    
   //function that checks if mouse in one of the four directions of the cat
   if (nextStepIsMouse(up, down, left, right, mouse))
   {
       return;  //we found a mouse in one of the four directions
   }

   updateTheNextStep(up, down,left,right,board,mouse,staticObjects);

}
//------------------------------------------------------------------------
//Function that checks if in one of the possible four directions the cat
//can move in the mouse is

bool SmartCat::nextStepIsMouse(sf::RectangleShape up, sf::RectangleShape down, sf::RectangleShape left,
                               sf::RectangleShape right, const std::unique_ptr<MovingObjects>& mouse)
{
    if (up.getPosition() == mouse->getPosition())
    {
        m_object.setPosition(up.getPosition());
        return true;
    }
   else if (down.getPosition() == mouse->getPosition())
    {
        m_object.setPosition(down.getPosition());
        return true;
    }
    else if (left.getPosition() == mouse->getPosition())
    {
        m_object.setTexture(HandleResources::instance().getObjectTexture(I_L_CAT));
        m_object.setPosition(left.getPosition());
        return true;
    }
    else if (right.getPosition() == mouse->getPosition())
    {
        m_object.setTexture(HandleResources::instance().getObjectTexture(I_R_CAT));
        m_object.setPosition(right.getPosition());
        return true;
    }
    return false;
}

//--------------------------------------------------------------------------
//This function finds which one of the four directions we can walk in has
//the shortest distance from cat, and is valid.
//Then, it sets the movement to that cell.

void SmartCat::updateTheNextStep (sf::RectangleShape up, sf::RectangleShape down,
                                  sf::RectangleShape left, sf::RectangleShape right, 
                                  const sf::RectangleShape& board, 
                                  const std::unique_ptr<MovingObjects>& mouse,
                                  const std::vector<std::unique_ptr<StaticObjects>>& staticObjects)

{
    float currDistance,
          shortestDistance = 10000;    //a big distance we will never recieve,
                                       //will change when the first currDistance is calculated
    //sf::Vector2f nextPosition = { 0,0 };

    if (validStep(up, board, staticObjects))
    {
        currDistance = distance(mouse->getPosition(), up.getPosition());
        if (currDistance < shortestDistance)
        {
            shortestDistance = currDistance;
           // nextPosition = up.getPosition();
           // checkCatCovered(up.getPosition(), staticObjects);
            m_object.setPosition(up.getPosition());
        }
    }
    if (validStep(down, board, staticObjects))
    {
        currDistance = distance(mouse->getPosition(), down.getPosition());
        if (currDistance < shortestDistance)
        {
            shortestDistance = currDistance;
            //nextPosition = down.getPosition();
            //checkCatCovered(down.getPosition(), staticObjects);
            m_object.setPosition(down.getPosition());
        }
    }
    if (validStep(left, board, staticObjects))
    {
        currDistance = distance(mouse->getPosition(), left.getPosition());
        if (currDistance < shortestDistance)
        {
            shortestDistance = currDistance;
           // nextPosition = left.getPosition();
            //checkCatCovered(left.getPosition(), staticObjects);
            m_object.setTexture(HandleResources::instance().getObjectTexture(I_L_CAT));
            m_object.setPosition(left.getPosition());
        }
    }
    if (validStep(right, board, staticObjects))
    {
        currDistance = distance(mouse->getPosition(), right.getPosition());
        if (currDistance < shortestDistance)
        {
            shortestDistance = currDistance;
            //nextPosition = right.getPosition();
            //checkCatCovered(right.getPosition(), staticObjects);
            m_object.setTexture(HandleResources::instance().getObjectTexture(I_R_CAT));
            m_object.setPosition(right.getPosition());
        }
    }
    //std::cout << "check if the cat coveres static object" << std::endl;
    //checkCatCovered(nextPosition, staticObjects);
    //m_object.setPosition(nextPosition);
}

//------------------------------------------------------------------------
//Function that checks if the cell the cat wants to move to is valid

bool SmartCat::validStep(sf::RectangleShape direction, const sf::RectangleShape &board,
                         const std::vector<std::unique_ptr<StaticObjects>>& staticObjects)
{
    //checking if inside board
    if (!isMovementValid(board, direction))
    {
        return false;
    }

    //checking if the cat's trying the move towards a wall or door
    for (int i = 0; i < staticObjects.size(); i++)
    {
        if (staticObjects[i]->getPosition() == m_object.getPosition())
        {
            //checking if in the wanted position there's a wall
            Wall* wallPtr = dynamic_cast<Wall*>(staticObjects[i].get());
            if (wallPtr != nullptr)
            {
                return false;
            }

            //checking if in the wanted position there's a door
            Door* doorPtr = dynamic_cast<Door*>(staticObjects[i].get());
            if (doorPtr != nullptr)
            {
                return false;
            }
        }
    }

    return true;
}
//------------------------------------------------------------------------
