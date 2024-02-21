
#include "GameObjects.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
GameObjects::GameObjects(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
    : m_object(size)
{
    m_object.setTexture(&picture);
    m_object.setPosition(position);
}
//------------------------------------------------------------------------
bool GameObjects::checkCollision(GameObjects& other)
{
    if (&other == this)
    {
        return false;
    }
    // check all 4 corners

    return m_object.getGlobalBounds().intersects(other.m_object.getGlobalBounds());
}
//-------------------------------------------------------------------------
void GameObjects::draw(sf::RenderWindow& window)
{
    window.draw(m_object);
}
////------------------------------------------------------------------------
//void GameObjects::setPosition(const sf::Vector2f& newPosition)
//{
//    m_object.setPosition(newPosition);
//}