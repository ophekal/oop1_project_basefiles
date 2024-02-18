
#include "StaticObjects.h"
#include "Cheese.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"


//------------------------------------------------------------------------
Cheese::Cheese (const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size)
  :StaticObjects(picture, position, size)
{

}