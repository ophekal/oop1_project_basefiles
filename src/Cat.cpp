
#include "Cat.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>

//------------------------------------------------------------------------
int Cat::m_count = 0;
//---------------------------------------------------------------
Cat::Cat(const sf::Texture& icon, const sf::Vector2f& position, const sf::Vector2f& size)
    : MovingObjects(icon, position, size)
{
    m_count++;
}

//------------------------------------------------------------------------
int Cat::getCount()
{
    return m_count;
 }