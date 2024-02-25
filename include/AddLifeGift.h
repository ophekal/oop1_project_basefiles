#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"


class AddLifeGift : public Gift
{
public:
	using Gift::Gift;
	virtual ~AddLifeGift() = default;
	//virtual void draw(sf::RenderWindow& window);	//a specific icon for adding life gift
	//virtual void collisionHandling(AddLifeGift&);	//mouse lives ++
	void collisionHandling(GameObjects& object);
	void collisionHandling(Mouse& mouse);
	void collisionHandling(Cat& cat);

	virtual void handleGift(Controller& controller);

private:

};