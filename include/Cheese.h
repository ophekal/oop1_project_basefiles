#pragma once
#include <SFML/Graphics.hpp>


Class Cheese:: public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Cheese() = default;
	virtual void draw(sf::RenderWindow& window);
	virtual void collisionHandling();

private:
};