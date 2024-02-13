#pragma once
#include <SFML/Graphics.hpp>


Class KillCatGift:: public Gift
{
public:
	using Gift::Gift;
	virtual ~Gift() = default;
	virtual void draw(sf::RenderWindow& window);	//a specific icon for killing cat gift
	virtual void collisionHandling();	//cat dies

private:

};