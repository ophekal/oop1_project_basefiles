#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"

class Door :: public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Door() = default;
	virtual void draw(sf::RenderWindow& window);
	virtual void collisionHandling();

private:
};