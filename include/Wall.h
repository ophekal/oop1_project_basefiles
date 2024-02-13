#pragma once
#include <SFML/Graphics.hpp>


class Wall:: public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Wall() = default;
	virtual void draw(sf::RenderWindow& window);
	virtual void collisionHandling();

private:
};