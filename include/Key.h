#pragma once
#include <SFML/Graphics.hpp>


Class Key:: public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Key() = default;
	virtual void draw(sf::RenderWindow& window);
	virtual void collisionHandling();

private:
};