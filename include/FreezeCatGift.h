#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class FreezeCatGift : public Gift
{
public:
	using Gift::Gift;
	virtual ~FreezeCatGift() = default;
	//virtual void draw(sf::RenderWindow& window);	//a specific icon for freeze cat gift
	//virtual void collisionHandling(FreezeCatGift& gift);	//freeze a cat
	void collisionHandling(GameObjects& object);
	void collisionHandling(Mouse& mouse);
	void collisionHandling(Cat& cat);

	virtual void handleGift(Controller& controller);
private:

};