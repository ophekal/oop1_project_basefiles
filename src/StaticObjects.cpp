
#include "GameObjects.h"
#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"



StaticObjects::GameObjects(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
    : m_object(size)