
#include "GameObjects.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

//----------------------------------------------------------------------------------------
GameObjects::GameObjects(const sf::Texture& picture, const sf::Vector2f& position,
                         const sf::Vector2f& size)
    : m_object(size),m_offBoard(false)
{
    m_object.setTexture(&picture);
    m_object.setPosition(position);
}

//----------------------------------------------------------------------------------------
bool GameObjects::checkCollision(GameObjects& other)
{
    if (&other == this)
    {
        return false;
    }

    float overLapping = 0.1f;
    float sizeDecrese = 1.3f;
    
    sf::FloatRect object = m_object.getGlobalBounds(),
                  otherObject = other.getGlobalBounds();

    object.left += object.width * overLapping;
    object.top += object.height * overLapping;
    object.width /= (sizeDecrese);
    object.height /= (sizeDecrese);

    otherObject.left += otherObject.width * overLapping;
    otherObject.top += otherObject.height * overLapping;
    otherObject.width /= (sizeDecrese);
    otherObject.height /= (sizeDecrese);

    return object.intersects(otherObject);
}

//-------------------------------------------------------------------------
void GameObjects::draw(sf::RenderWindow& window)
{
    window.draw(m_object);
}

//--------------------------------------------------------------------------
bool GameObjects::offBoard()const
{
    return m_offBoard;
}

//--------------------------------------------------------------------------
void GameObjects::setOffBoard(bool off)
{
    m_offBoard = off;
}

//--------------------------------------------------------------------------
const sf::FloatRect GameObjects::getGlobalBounds()const
{
    return m_object.getGlobalBounds();
}
