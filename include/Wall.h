#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"

class Wall:public StaticObjects
{
public:
	Wall(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~Wall() = default;
	virtual void collisionHandling(GameObjects& object);
	virtual void collisionHandling(Mouse& mouse);
	virtual void collisionHandling(Cat& cat);

private:
};