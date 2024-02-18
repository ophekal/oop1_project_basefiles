#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"

class Door : public StaticObjects
{
public:
	Door(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual void draw(sf::RenderWindow& window);
	virtual void collisionHandling();

private:
};