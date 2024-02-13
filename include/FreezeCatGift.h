#pragma once
#include <SFML/Graphics.hpp>


Class FreezeCatGift:: public Gift
{
public:
	using Gift::Gift;
	virtual ~FreezeCatGift() = default;
	virtual void draw(sf::RenderWindow& window);	//a specific icon for freeze cat gift
	virtual void collisionHandling();	//freeze a cat

private:

};