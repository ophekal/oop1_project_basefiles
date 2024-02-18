#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"

class Key:public StaticObjects
{
public:
	Key(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~Key() = default;
	//virtual void draw(sf::RenderWindow& window);
	virtual void collisionHandling();

private:
};