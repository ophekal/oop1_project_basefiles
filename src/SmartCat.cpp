#include "StaticObjects.h"
#include "Cat.h"
#include "SmartCat.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
void SmartCat::movement(sf::Time deltaTime, const sf::RectangleShape& board)
{
	MovingObjects::setObjectSpeed(40.f);

    sf::RectangleShape newPosition = m_object;
    newPosition.move(m_direction * m_objectSpeed * deltaTime.asSeconds());

    Location up(m_position.x - 1, m_position.y),
        down(m_location.row + 1, m_location.col),
        left(m_location.row, m_location.col - 1),
        right(m_location.row, m_location.col + 1),
        nextLocation(-1, -1);

    char upChar = board.readChar(up),
        downChar = board.readChar(down),
        leftChar = board.readChar(left),
        rightChar = board.readChar(right);

    if (nextCharMouse(upChar, downChar, leftChar, rightChar, nextLocation))
    {
        m_location = nextLocation;
        m_standOnTop = '%';
        return (*this);
    }

    char onTop;

    //function that checks all four possible directions, and finds the shortest distance
    updateTheNextStep(cats, mouseLocation, up, down, left, right, nextLocation, upChar,
        downChar, leftChar, rightChar, onTop, catIndex);

    m_location = nextLocation;
    m_standOnTop = onTop;
    return (*this);
}

//------------------------------------------------------------------------
//Function that checks if in the cell the cat is moving to there's a mouse

bool Cat::nextCharMouse(char upChar, char downChar, char leftChar, char rightChar, Location& nextMovement) const
{
    if (upChar == '%')
    {
        nextMovement = Location(m_location.row - 1, m_location.col);
        return true;
    }
    else if (downChar == '%')
    {
        nextMovement = Location(m_location.row + 1, m_location.col);
        return true;
    }
    else if (leftChar == '%')
    {
        nextMovement = Location(m_location.row, m_location.col - 1);
        return true;
    }
    else if (rightChar == '%')
    {
        nextMovement = Location(m_location.row, m_location.col + 1);
        return true;
    }
    return false;
}

//--------------------------------------------------------------------------
//This function finds which one of the four directions we can walk in has
//the shortest distance from cat, and is valid.
//Then, it sets the movement to that cell.

void Cat::updateTheNextStep(std::vector<Cat>& cats, const Location& mouseLocation, const Location& up, const Location& down, const Location& left,
    const Location& right, Location& nextLocation,
    char upChar, char downChar, char leftChar, char rightChar, char& onTop, int catIndex)
{
    double shortestDistance = 10000,    //a big distance we will never recieve, will change when the first currDistance is calculated
        currDistance;

    if (validStep(upChar))
    {
        currDistance = distance(mouseLocation, up);
        if (currDistance < shortestDistance)
        {
            shortestDistance = currDistance;
            nextLocation = up;
            onTop = upChar;
        }
    }
    if (validStep(downChar))
    {
        currDistance = distance(mouseLocation, down);
        if (currDistance < shortestDistance)
        {
            shortestDistance = currDistance;
            nextLocation = down;
            onTop = downChar;
        }
    }
    if (validStep(leftChar))
    {
        currDistance = distance(mouseLocation, left);
        if (currDistance < shortestDistance)
        {
            shortestDistance = currDistance;
            nextLocation = left;
            onTop = leftChar;
        }
    }
    if (validStep(rightChar))
    {
        currDistance = distance(mouseLocation, right);
        if (currDistance < shortestDistance)
        {
            shortestDistance = currDistance;
            nextLocation = right;
            onTop = rightChar;
        }
    }

    if (onTop == '^')
    {
        updateOnTop(cats, nextLocation, catIndex, onTop);
    }
}
//------------------------------------------------------------------------
//This function deals with a case where we have more than one cat in the
//same cell. It updates the member onTop of the cat we're currently at
//to be the same as the onTop of the different cat that's in the same cell.

void Cat::updateOnTop(std::vector<Cat>& cats, const Location& nextLocation, int catIndex, char& onTop)
{

    for (int index = 0; index < cats.size(); index++)
    {
        Location currCat = cats[index].getLocation();
        if (index != catIndex && (currCat.col == nextLocation.col) && (currCat.row == nextLocation.row))
        {
            Cat kitten = cats[index];
            onTop = kitten.getStandOnTop();
            cats[index].setStandOnTop('^');
        }
    }


}

//------------------------------------------------------------------------
//Function that checks if the character in the cell we won't to move to is
//one that the cat can stand on

bool Cat::validStep(char character) const
{
    if (character == '#' ||
        character == '-' ||
        character == 'D')
    {
        return false;
    }

    return true;
}
//-------------------------------------------------------------
void Cat::print()const
{
    std::cout << "^";
}
