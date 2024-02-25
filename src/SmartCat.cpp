#include "StaticObjects.h"
#include "Cat.h"
#include "SmartCat.h"
#include "GameObjects.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
void SmartCat::movement(sf::Time deltaTime, const sf::RectangleShape& board,
                        const std::vector<std::unique_ptr<MovingObjects>>& cats,
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
       
   }



 //   //function that checks all four possible directions, and finds the shortest distance
 //   updateTheNextStep(cats, mouseLocation, up, down, left, right, nextLocation, upChar,
 //       downChar, leftChar, rightChar, onTop, catIndex);

 //   m_location = nextLocation;
 //   m_standOnTop = onTop;
 //   return (*this);
}
//------------------------------------------------------------------------
//Function that checks if in the cell the cat is moving to there's a mouse

bool SmartCat::nextStepIsMouse(sf::RectangleShape up, sf::RectangleShape down, sf::RectangleShape left,
                               sf::RectangleShape right, const std::unique_ptr<MovingObjects>& mouse) const
{
    if (up.getPosition() == mouse->getPosition())
    {
        sf::Vector2f position = up.getPosition();
        m_object.setPosition(position.x, position.y);
        return true;
    }
   /* else if (down.getPosition() == mouse->getPosition())
    {
        m_object.setPosition(down.getPosition());
        return true;
    }
    else if (left.getPosition() == mouse->getPosition())
    {
        m_object.setPosition(left.getPosition());
        return true;
    }
    else if (right.getPosition() == mouse->getPosition())
    {
        m_object.setPosition(right.getPosition());
        return true;
    }*/
    return false;
}

////--------------------------------------------------------------------------
////This function finds which one of the four directions we can walk in has
////the shortest distance from cat, and is valid.
////Then, it sets the movement to that cell.
//
//void Cat::updateTheNextStep(std::vector<Cat>& cats, const Location& mouseLocation, const Location& up, const Location& down, const Location& left,
//    const Location& right, Location& nextLocation,
//    char upChar, char downChar, char leftChar, char rightChar, char& onTop, int catIndex)
//{
//    double shortestDistance = 10000,    //a big distance we will never recieve, will change when the first currDistance is calculated
//        currDistance;
//
//    if (validStep(upChar))
//    {
//        currDistance = distance(mouseLocation, up);
//        if (currDistance < shortestDistance)
//        {
//            shortestDistance = currDistance;
//            nextLocation = up;
//            onTop = upChar;
//        }
//    }
//    if (validStep(downChar))
//    {
//        currDistance = distance(mouseLocation, down);
//        if (currDistance < shortestDistance)
//        {
//            shortestDistance = currDistance;
//            nextLocation = down;
//            onTop = downChar;
//        }
//    }
//    if (validStep(leftChar))
//    {
//        currDistance = distance(mouseLocation, left);
//        if (currDistance < shortestDistance)
//        {
//            shortestDistance = currDistance;
//            nextLocation = left;
//            onTop = leftChar;
//        }
//    }
//    if (validStep(rightChar))
//    {
//        currDistance = distance(mouseLocation, right);
//        if (currDistance < shortestDistance)
//        {
//            shortestDistance = currDistance;
//            nextLocation = right;
//            onTop = rightChar;
//        }
//    }
//
//    if (onTop == '^')
//    {
//        updateOnTop(cats, nextLocation, catIndex, onTop);
//    }
//}
////------------------------------------------------------------------------
////This function deals with a case where we have more than one cat in the
////same cell. It updates the member onTop of the cat we're currently at
////to be the same as the onTop of the different cat that's in the same cell.
//
//void Cat::updateOnTop(std::vector<Cat>& cats, const Location& nextLocation, int catIndex, char& onTop)
//{
//
//    for (int index = 0; index < cats.size(); index++)
//    {
//        Location currCat = cats[index].getLocation();
//        if (index != catIndex && (currCat.col == nextLocation.col) && (currCat.row == nextLocation.row))
//        {
//            Cat kitten = cats[index];
//            onTop = kitten.getStandOnTop();
//            cats[index].setStandOnTop('^');
//        }
//    }
//
//
//}
//
////------------------------------------------------------------------------
////Function that checks if the character in the cell we won't to move to is
////one that the cat can stand on
//
//bool Cat::validStep(char character) const
//{
//    if (character == '#' ||
//        character == '-' ||
//        character == 'D')
//    {
//        return false;
//    }
//
//    return true;
//}
////-------------------------------------------------------------
//void Cat::print()const
//{
//    std::cout << "^";
//}
