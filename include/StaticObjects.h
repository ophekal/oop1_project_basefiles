#pragma once
#include <SFML/Graphics.hpp>


class StaticObjects:: public GameObjects
{
public:
	using GameObjects::GameObjects;
	virtual ~StaticObject() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void collisionHandling() = 0;

private:
	bool currOnBoard = false;
};