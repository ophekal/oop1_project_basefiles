#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"


class AddTimeGift: public Gift
{
public:
	using Gift::Gift;
	virtual ~AddTimeGift() = default;
	//virtual void draw(sf::RenderWindow& window);	//a specific icon for adding time gift
	//virtual void collisionHandling(AddTimeGift&);	//game time ++
	void collisionHandling(GameObjects& object);
	void collisionHandling(Mouse& mouse);
	void collisionHandling(Cat& cat);

private:

};