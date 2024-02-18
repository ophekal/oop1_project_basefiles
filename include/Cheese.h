#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"


class Cheese: public StaticObjects
{
public:
	Cheese (const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~Cheese() = default;
	//virtual void draw(sf::RenderWindow& window);
	virtual void collisionHandling(GameObjects&);
	virtual void collisionHandling(Mouse&);
	virtual void collisionHandling(Cat&);

private:
};