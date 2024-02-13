#pragma once
#include <SFML/Graphics.hpp>


Class Gift:: public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Gift() = default;
	virtual void draw(sf::RenderWindow& window)=0;	//each gift will have a different icon so virtual here
	virtual void collisionHandling() = 0;

private:

};