#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class KillCatGift: public Gift
{
public:
	using Gift::Gift;
	virtual ~KillCatGift() = default;
	virtual void draw(sf::RenderWindow& window);	//a specific icon for killing cat gift
	virtual void collisionHandling();	//cat dies

private:

};