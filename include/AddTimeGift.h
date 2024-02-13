#pragma once
#include <SFML/Graphics.hpp>


Class AddTimeGift:: public Gift
{
public:
	using Gift::Gift;
	virtual ~AddTimeGift() = default;
	virtual void draw(sf::RenderWindow& window);	//a specific icon for adding time gift
	virtual void collisionHandling();	//game time ++

private:

};